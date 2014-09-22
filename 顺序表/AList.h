
#ifndef ALIST_H_
#define ALIST_H_

/************************************************************************/
/* 顺序表     
   缺点： 当超过最大maxSize的时候 ，将重新分配空间，并有copy的操作

   此处不做改进
*/
/************************************************************************/

#include "List.h"

template<class Elem>
class Alist:public List<Elem>{
private:
	int maxSize ;
	int listSize;
	int fence ;
	Elem * listArray ;
	enum{defaultSize = 10};
public:
	Alist(int size = defaultSize)
	{
		maxSize = size ;
		listSize = 0 ;
		fence = 0;
		listArray = new Elem[maxSize];
	}

	~Alist(){ 
		delete [] listArray;
	}
	
	void clear(){
		delete [] listArray;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}

	bool insert(const Elem & it){
		// insert an item to the fence position
		if(listSize == maxSize) return false ;
		for (int i = listSize ;i > fence ;i--)
		{
			listArray[i] = listArray[i-1];
		}
		listArray[fence] = it;
		listSize++;
		return true ;
	}
	bool append(const Elem & it){
		if(listSize == maxSize) return false;
		listArray[listSize++] = it;
		return true;
	}
	bool remove(Elem & it) {
		if(rightLength() == 0) return false ;
		for (int i = fence ;i <listSize-1;i++)
		{
			listArray[i] = listArray[i+1];
		}
		listSize--;
		return true;
	}

	void setStart(){
		fence = 0 ;
	}

	void setEnd(){
		fence = listSize;
	}

	bool getFirst(Elem & it){
		if (listSize == 0)
		{
			return false ;
		}

		it = listArray[0];
		return true;
	}
	bool getEnd(Elem & it) {
		if (listSize == 0)
		{
			return false;
		}
		it = listArray[listSize - 1];
		return true ;
	}

	void prev() {
		if(fence > 0)
			fence--;
	}
	void next() {
		if(fence < listSize)
			fence++;
	}

	int leftLength() {
		return fence;
	}
	int rightLength(){
		return listSize - fence;
	}
	bool setPos(int pos){
		if(pos >= 0 && pos < listSize){
			fence = pos ;
		}
		return false;
	}
	bool getValue(Elem& it) const {
		if(fence >=0 && fence < listSize)
		{
			it = listArray[fence] ;
			return true;
		}
		return false;
	}

	void print() const{

	}
};

#endif

