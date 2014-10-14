

#ifndef LQUEUE_H_
#define LQUEUE_H_

/************************************************************************/
/* 
	using link to realize queue
*/
/************************************************************************/

#include "Link.h"
#include "Queue.h"

template<class Elem>
class LQueue:public Queue<Elem>{
private:
	int size ; // to record the size of queue
	Link<Elem> * front ;
	Link<Elem> * rear ;
public:
	LQueue(){
		size = 0 ;
		front = rear = NULL;
	}
	~LQueue(){
		clear();
	}

	bool enqueue(const Elem & it) {
		if (front == NULL)
		{
			front = rear = new Link<Elem>(it,NULL);
		}
		else{
			rear->next = new Link<Elem>(it,NULL); 
			rear = rear->next ;
		}
		size++;
		return true ;
	}
	bool dequeue(Elem & it){
		Link<Elem > * temp ;
		if (front == NULL)
		{
			return false ;
		}
		else{
			it = front->element ;
			temp = front;
			front = temp->next ;
			delete temp;
			size--;
			return true;
		}
	}
	void clear(){
		Link<Elem> * temp ;
		while (front)
		{
			temp = front ;
			front = front->next ;
			delete temp ;
		}
		size = 0;
		temp = NULL;
	}
	bool frontValue(Elem & it){
		if (front)
		{
			it = front->element;
			return true;
		}
		return false;
	}
};

#endif



