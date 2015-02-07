#ifndef OBJECT_HOLDER_H
#define OBJECT_HOLDER_H
/***********************************************************************
* ObjectHolder.h
* Rohit Joshi
* 08-25/2004
* ObjectHolder is a container class who holds the object 
* It Contains Object T* m_pObj and long m_nTimeStap member variables 
*
***********************************************************************/

template<class T>
class ObjectHolder
{
public:
	// constructor
	ObjectHolder()
	{
		m_nTimeStamp = -1;
		m_pObj = NULL;
	}
	// distructor
	~ObjectHolder()
	{
		if(m_pObj) {
			m_pObj->Release();
			m_pObj = NULL;
		}
		m_pObj = NULL; 

	}
	//Initliaze object
	void InitObject()
	{
		if(!m_pObj) 
		{
			m_pObj = new T();
			m_pObj->Init();
		}
	}
	// Get the object
	T* GetObj()
	{
		return m_pObj;
	}
	// set the object
	void SetObject(T* pObj = NULL)
	{
		m_pObj = pObj;
	}
	// get timestamp
	long GetTimeStamp()
	{
		return m_nTimeStamp;
	}
	//set timestamp
	void SetTimeStamp(long nTime)
	{
		m_nTimeStamp = nTime;
	}
	// set object and timestamp
	void Set(T* pObj,long nTime)
	{
		m_pObj = pObj;
		m_nTimeStamp = nTime;
	}


private:
	T *m_pObj;  // object pointer
	long  m_nTimeStamp;  // timestamp

};


#endif //OBJECT_HOLDER_H
