

/************************************************************************/
/* 
	using list array to realize circle queue
*/
/************************************************************************/

#ifndef AQUEUE
#define AQUEUE

#include "Queue.h"

template <class Elem> class AQueue:public Queue<Elem>{
private:
	int size ;
	int front ;
	int rear ;
	int count ;				// to record the number of queue
	Elem * listArray ;
	enum{defaultSize = 5};
public:
	AQueue(int size = defaultSize){
		this->size = size;
		front = rear = count = 0;			
		listArray = new Elem[size];
	}

	~AQueue(){
		delete [] listArray ;
	}
	
	// count = rear - front
	bool enqueue(const Elem & it){
		if (count == size)
		{
			return false;
		}
		listArray[rear%size] = it;
		count++;
		rear++;
		return true ;
	}

	bool dequeue(Elem & it) {
		if (count == 0)
		{
			return false ;
		}
		it = listArray[front%size];
		count--;
		front++ ;
		return true ;
	}

	void clear() {
		front = rear = count = 0;
	}

	bool frontValue(Elem & it) {
		if (count == 0)
		{
			return false;
		}

		it = listArray[front%size];
		return true;
	}

	int length(){
		return count ;
 	}
};

#endif