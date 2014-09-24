
#include "stdafx.h"

/************************************************************************/
/* 
	using linklist to realize stack
*/
/************************************************************************/

#ifndef LSTACK_H_
#define LSTACK_H_

#include "Link.h"
#include "Stack.h"

template <class Elem>
class LStack:public Stack<Elem>{
private:
	int size ;
	Link<Elem> * top ;
public:
	LStack(){
		size = 0 ;
		top = NULL ;
	}
	~LStack(){
		clear();
	}

	bool push(const Elem & item) {
		top = new Link<Elem>(item,top) ;
		size++ ;
		return true ;
	}

	// problem here 
	bool pop(const Elem & item) {
		Link<Elem> * temp = top;
		if (size == 0)
		{
			return false ;
		}
		
		item = temp->element ;

		top = top->next ;
		delete temp ;
		size--;
		return true ;
	}
	
	bool topValue(Elem & item) const{
		if (size == 0)
		{
			return false ;
		}

		item = top->element ;
		return true ;

	}
	void clear()  {
		Link<Elem> * temp ;
		while (top)
		{
			temp = top ;
			top = top->next ;
			delete temp ;
		}
		size = 0 ;
	}
};

#endif