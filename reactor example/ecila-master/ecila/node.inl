template <typename T>
inline T* Node::FindObject(const char_t *path)
{
	ECILA_ASSERT(path);

	Tokenizer t;
	uint32_t count = t.CTokenize(path, "/");
	if(count == 0) { ECILA_TRACE(); return 0; }

	Node *node = this;
	MAP_T *child = &child_;
	for(uint32_t i=0; i<count - 1; i++)
	{
		ITER_T iter = child->find(t.Token(i));
		if(iter == child->end()) { ECILA_TRACE(); return 0; }

		node = iter->second;
		child = &node->child_;
	}

	return node->FindChild<T>(t.Token(count - 1));
}








template <typename T>
inline T* Node::FindChild(const char_t *name)
{
	ECILA_ASSERT(name);

	ITER_T iter = child_.find(name);
	if(iter == child_.end()) { ECILA_TRACE(); return 0; }

	T* child = dynamic_cast<T*>(iter->second);
	return child;
}








inline uint32_t Node::Depth()
{
	return depth_;
}








inline void Node::Name(const char_t *name)
{
	name_ = name;
}








inline const char_t* Node::Name()
{
	return name_.c_str();
}

