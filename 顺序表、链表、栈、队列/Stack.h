
#ifndef MYSTACK
#define MYSTACK

/************************************************************************/
/* 
	define the basic operation of stack
*/
/************************************************************************/


template <class Elem> class Stack{
public:
	virtual bool pop(const Elem &) = 0;
	virtual bool push(const Elem &) = 0;
	virtual bool topValue(Elem &) const= 0;
	virtual void clear() = 0 ;
};

#endif