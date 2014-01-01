template <typename T>
Pool<T>::Pool()
{
	capacity_	= 0;
	inc_size_	= 0;
}







template <typename T>
Pool<T>::~Pool()
{
	Finalize();
}








template <typename T>
bool_t Pool<T>::Initialize(uint32_t capacity, uint32_t inc_size)
{
	ECILA_ASSERT(capacity > 1);
	ECILA_ASSERT(inc_size >= 0);

	capacity_ = capacity;
	inc_size_ = inc_size;
	
	if(!reps_list_.empty())
	{
		ECILA_TRACE();
		return FALSE;
	}

	try
	{
		T* rep = new T[capacity_];
		if(!rep) { ECILA_TRACE(); return FALSE; }

		//reps list
		reps_list_.push_back(rep);

		//free list
		for(uint32_t i=0; i<capacity_; i++)
		{
			free_list_.push_back(&rep[i]);
		}
	}
	catch(...)
	{
		ECILA_TRACE();
		return FALSE;
	}

	return TRUE;
}








template <typename T>
bool_t Pool<T>::Finalize()
{
	capacity_	= 0;
	inc_size_	= 0;

	for(ITER_T iter = reps_list_.begin(); iter != reps_list_.end(); ++iter)
	{
		T* rep = *iter;
		ECILA_SAFE_DELETE_ARRAY(rep);
	}
	reps_list_.clear();

	return TRUE;
}






template <typename T>
inline T* Pool<T>::Acquire(const char_t *func, int32_t line)
{
	if(free_list_.empty())
	{
		if(inc_size_ == 0) { ECILA_TRACE(); return 0; }

		try
		{
			T* rep = new T[inc_size_];
			if(!rep) { ECILA_TRACE(); return FALSE; }

			//reps list
			reps_list_.push_back(rep);
			capacity_ += inc_size_;

			//free list
			for(uint32_t i=0; i<inc_size_; i++)
			{
				free_list_.push_back(&rep[i]);
			}
		}
		catch(...)
		{
			ECILA_TRACE(); return 0;
		}
	}

	T* t = free_list_.front();
	free_list_.pop_front();

	return t;
}








template <typename T>
inline bool_t Pool<T>::Release(T *t)
{
	if(!t)
	{
		ECILA_TRACE();
		return FALSE;
	}

	free_list_.push_front(t);

	return TRUE;
}








template <typename T>
inline uint32_t Pool<T>::Capacity()
{
	return capacity_;
}








template <typename T>
inline uint32_t Pool<T>::Remain()
{
	return free_list_.size();
}

