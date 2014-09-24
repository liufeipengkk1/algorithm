
#ifndef ASTACK_H_
#define ASTACK_H_

/************************************************************************/
/* 
	using arraylist to realize stack
*/
/************************************************************************/

#include "Stack.h"

template <class Elem> class AStack:public Stack<Elem>{
private:
	int size ;
	int top ;
	enum {defaultSize = 10};
	Elem * listArray ;
public:
	AStack(int size = defaultSize){
		this->size = size ;
		top = 0 ;
		listArray = new Elem[size] ;
	}
	~AStack(){
		delete [] listArray ;
	}
	bool push(const Elem & item){
		if (top == size)
		{
			return false ;
		}
		
		listArray[top++] = item ;
		return true;
	}

	bool pop(Elem & item) = 0{
		if (top == 0)
		{
			return false ;
		}
		
		item = listArray[--top];
	}
	bool topValue(Elem & item) const{
		if (top == 0)
		{
			return false ;
		}
		
		item = listArray[top-1];
		return true ;
	}

	void clear(){
		top = 0 ;
	}

};

#endif