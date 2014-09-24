
#ifndef LINK
#define LINK

/************************************************************************/
/*  design node template for linkList                                     
*/
/************************************************************************/

template <class Elem> class Link{
public:
	Elem element;
	Link * next ;
	Link( const Elem & elemval,Link * nextval = NULL){
		element = elemval ;
		next = nextval;
	}
	Link(Link * nextval = NULL){
		next = nextval;
	}
};

/************************************************************************/
/* design the abstract class for linkList
	offer the basic function for linkList
*/
/************************************************************************/

template <class Elem> class LinkList {
public:
	virtual bool append(const Elem &) = 0;			//add a node
	virtual bool insert(const Elem &) = 0;			//insert a node
	virtual bool remove(Elem & it) = 0;
	virtual bool clear() = 0 ;
	virtual bool getValue(Elem &) const = 0;	
	virtual bool next() = 0;
	virtual bool prev() = 0;
	virtual void setStart() =0;
	virtual void setEnd()=0;
	virtual bool isEOF()=0;
};

template <class Elem> class LLinList:public LinkList<Elem>{
private:
	Link<Elem> * head ;
	Link<Elem> * tail;
	Link<Elem> * fence;
	void init(){
		fence = head = tail = NULL;
	}
	void removeall(){
		while (head != NULL)
		{
			fence = head;
			head = head->next;
			delete fence;
		}
	}

public:
	LLinList(){ init() ;}
	~LinkList() { removeall() ;}

	void clear() { 
		removeall() ;
		init();
	}

	bool append(const Elem & item){
		if(head == NULL)
			fence = head = tail = new Link<Elem>(item,NULL);
		else
			tail = tail->next = new Link<Elem>(item,NULL);
		return true ;
	}

	bool insert(const Elem & item) {
		fence->next = new Link<Elem>(item,fence->next);
		if(fence == tail)
			tail = fence->next ;
		return true ;
	}

	
	bool remove(Elem & item){
		if (fence == NULL)
		{
			return false ;
		}
		else if(fence == head){
			head = fence->next ;
			item = fence->element ;
			delete fence ;
			fence = head ;
		}
		else if(fence == tail){
			Link<Elem> * temp = head ;
			while (temp->next != fence)
			{
				temp = temp->next ;
			}

			tail = temp ;
			item = fence->element ;
			delete fence ;
			fence =  tail ;
			fence->next = NULL;
		}
		else{
			Link<Elem> * temp = head ;
			while (temp->next != fence)
			{
				temp = temp->next ;
			}
			temp->next = fence->next ;
			item = fence->element ;
			delete fence ;
			fence = temp ;
		}
		return true ;
	}

	bool getValue(Elem & item) const {
		if(fence == NULL)
			return false ;
		item = fence->element;
		return true;
	}

	bool next() {
		if(fence == tail)
			return false ;
		fence =fence->next ;
		return true ;
	}

	bool prev() {
		Link<Elem> * temp = head ;
		if (fence == head)
		{
			return false ;
		}

		while(temp->next != fence){
			temp = temp->next ;
		}
		
		fence = temp ;

		return true ;
		
	}

	void setStart() {
		fence = head ;
	}
	virtual void setEnd(){
		fence = tail ;
	}
	bool isEOF(){
		if(fence->next == NULL)
			return true ;
		return false;
	}
};

#endif