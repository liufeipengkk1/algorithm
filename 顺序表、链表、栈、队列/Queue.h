

#ifndef MYQUEUE
#define MYQUEUE

/************************************************************************/
/* 
	define the api of queue
*/
/************************************************************************/

template <class Elem> class Queue{
public:
	virtual bool enqueue(const Elem &) = 0 ;
	virtual bool dequeue(Elem &) = 0 ;
	virtual void clear() = 0 ;
	virtual bool frontValue(Elem &) = 0;
};

#endif