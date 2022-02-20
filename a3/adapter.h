#ifndef STACK_H
#define STACK_H
#include "dlist.h"
//version 1.1, added empty functions to constr/destr of stack
//This is the target
class Stack
{
  public:
	Stack() {}
	virtual void push(const int &o) = 0;
	virtual void pop() = 0;
	virtual int top() const = 0;
	virtual bool isEmpty() = 0;
	virtual int numItems() = 0;
	virtual ~Stack() {}
};

//class below is not completed... you must structure this as a object adapter
//with appropriate requests and calls inheritance structure etc.
class ObjectAdapter : public Stack
{
	DList *dl;

  public:
	ObjectAdapter();
	virtual void push(const int &o);
	virtual void pop();
	virtual int top() const;
	virtual bool isEmpty();
	virtual int numItems();
	~ObjectAdapter();
};
ObjectAdapter::ObjectAdapter()
{
	dl = new DList();
}
void ObjectAdapter::push(const int &val)
{
	dl->push_back(val);
}
void ObjectAdapter::pop()
{
	dl->pop_back();
}
int ObjectAdapter::top() const
{
	DList::iterator it = dl->end();
	--it;
	return *it;
}
bool ObjectAdapter::isEmpty()
{
	return dl->empty();
}
int ObjectAdapter::numItems()
{
	return dl->size();
}
ObjectAdapter::~ObjectAdapter()
{
}

//class below is not completed... you must structure this as a class adapter
//with appropriate requests and calls inheritance structure etc.
class ClassAdapter : public Stack, public DList
{
	//DList* DList;

  public:
	ClassAdapter();
	virtual void push(const int &o);
	virtual void pop();
	virtual int top() const;
	virtual bool isEmpty();
	virtual int numItems();
	//~ClassAdapter();
};
ClassAdapter::ClassAdapter()
{
	DList *dl = new DList();
}
void ClassAdapter::push(const int &val)
{
	DList::push_back(val);
}
void ClassAdapter::pop()
{
	DList::pop_back();
}
int ClassAdapter::top() const
{
	const_iterator it = DList::cend();
	--it;
	return *it;
};
bool ClassAdapter::isEmpty()
{
	return DList::empty();
};
int ClassAdapter::numItems()
{
	return DList::size();
};

#endif
