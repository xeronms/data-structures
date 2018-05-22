#ifndef S_L_LIST_H
#define S_L_LIST_H



template<typename T>
class singly_linked_list {
protected:


	template<typename T>
	class element{
	public:
			T* data;
			element* next;
			element* prev;

			element():next(NULL), prev(NULL), data(NULL){}
			element(T& a):data(&a),next(NULL), prev(NULL){}
	};

	
	element<T> *head;
	//element<T> *tail;

	int l_size;



public:


	singly_linked_list():head(NULL), l_size(0){}
	

	void push(T& e);
	T pop();
	void clear();
	element<T>* front() const;
	element<T>* next(element<T> *) const;
	element<T>* next() const;
	int size()const{ return l_size;}
	bool operator==(singly_linked_list<T>& );
	bool operator!=(singly_linked_list<T>& );



	class iterator{
		element<T>* current;
		singly_linked_list<T>& li;

	public:
		iterator(singly_linked_list<T>& l):li(l),current(l.front()){}
		iterator(iterator& it):li(it.li),current(it.current){} //konstr. kopiujacy, potrzebny do operator++(int)
		iterator& operator++();
		iterator operator++(int);
		T operator*();
		operator bool() const;
	};

};




template<typename T>
void singly_linked_list<T>::push(T& e){ // z³o¿onoœæ czasowa dla push front O(1)

	element<T>* node;

	node = new element<T>(e);
	node->next = head;
	head = node;
	++l_size;
}



template<typename T>
T singly_linked_list<T>::pop(){ // O(1)
	
	element<T>* tmp;
	T data = *head->data;

	tmp = head->next;
	delete head;
	head = tmp;
	--l_size;

	return data;
}




template<typename T>
void singly_linked_list<T>::clear(){

	while (l_size){
		pop();
	}
}


template<typename T>
typename singly_linked_list<T>::element<T>* singly_linked_list<T>::front() const{
	return head;
}


template<typename T>
typename singly_linked_list<T>::element<T>* singly_linked_list<T>::next(typename singly_linked_list<T>::element<T>* const e) const{
	return e.next; 
}

template<typename T>
typename singly_linked_list<T>::element<T>* singly_linked_list<T>::next() const{
	return front(); 
}



template<typename T>
bool singly_linked_list<T>::operator==(singly_linked_list<T>& L){
	if ( l_size != L.l_size ) 
		return 0;
	

	for (int k=0; k<l_size; ++k){
		if (next() != L.next()) 
			return 0;
	}

	return 1;
}


template<typename T>
bool singly_linked_list<T>::operator!=(singly_linked_list<T>& L){
	return !(*this==L);
}




template<typename T>
typename singly_linked_list<T>::iterator & singly_linked_list<T>::iterator::operator++(){
	
	if ( current ) current = current->next;
	return *this;
}



template<typename T>
typename singly_linked_list<T>::iterator singly_linked_list<T>::iterator::operator++(int){
	
	iterator it(*this);

	if ( current ){	
		current = current->next;
	}
	return it;
}
		


template<typename T>
T singly_linked_list<T>::iterator::operator*(){
	
	return *current->data;

}

template<typename T>
singly_linked_list<T>::iterator::operator bool() const{
	
	return current != NULL;
}



#endif