#pragma once



#include <map>
#include <string>

#include "tokenizer.h"


#ifndef CLASSNAME

#define CLASSNAME(classname) \
	virtual const char_t* ClassName() const \
	{ \
		return classname; \
	}

#endif






NS_ECILA_START

class DECL_SPEC_DLL Node
{
public:
	typedef std::map< std::string, Node * > MAP_T;
	typedef MAP_T::iterator					ITER_T;

			 Node();
	virtual ~Node();


	CLASSNAME("Node");


	bool_t Attach(Node *node);
	bool_t Detach(Node *node);
	void   Dump();

	template <typename T>
	T* FindObject(const char_t *path);

	template <typename T>
	T* FindChild(const char_t *name);

	uint32_t Depth();

	void Name(const char_t *name);
	const char_t* Name();

	ITER_T BeginIter()	{ return child_.begin(); }
	ITER_T EndIter()	{ return child_.end(); }


private:

	uint32_t	depth_;
	Node		*parent_;
	MAP_T		child_;
	std::string	name_;

	virtual void DUMPSPEC();
};

#include "node.inl"

NS_ECILA_END

