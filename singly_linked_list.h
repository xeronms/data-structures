#ifndef S_L_LIST_H
#define S_L_LIST_H

template<typename T>
class element{
public:
		T* data;
		element* next;
		element* prev;

		element():next(NULL), prev(NULL), data(NULL){}
		element(T& a):data(&a),next(NULL), prev(NULL){}

};



template<typename T>
class singly_linked_list {
protected:

	element<T> *head;
	//element<T> *tail;
	int l_size;
	int i;


public:

	singly_linked_list():head(NULL), l_size(0), i(0){}
	
	void push(T& e);
	T pop();
	void clear();
	T front();
	T next();
	int size()const{ return l_size;}
	bool operator==(singly_linked_list<T>& );
	bool operator!=(singly_linked_list<T>& );

};




template<typename T>
void singly_linked_list<T>::push(T& e){

	element<T>* node;

	node = new element<T>(e);
	node->next = head;
	head = node;
	++l_size;
}


template<typename T>
T singly_linked_list<T>::pop(){
	
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
T singly_linked_list<T>::front(){
	i = 1;
	return *head->data;
}


template<typename T>
T singly_linked_list<T>::next(){
	element<T>* e = head;
	
	for (int j=0; j<i; ++j){
		e = e->next;
	}
	
	++i;
	return *e->data;
}


template<typename T>
bool singly_linked_list<T>::operator==(singly_linked_list<T>& L){
	if ( l_size != L.l_size ) return 0;
	
	int i1 = i, i2 = L.i; //zapamietanie indexu 'i'. bêdziemy u¿ywaæ funkcji next, i nie chcemy niektontrolowanie zmieniac wartoœæ i 
	
	if (front() != L.front()){
		i = i1; L.i = i2;
		return 0;
	}

	for (int k=0; k<l_size; ++k){
		if (next() != L.next()){
			i = i1; L.i = i2;
			return 0;
		}
	}

	return 1;
}

template<typename T>
bool singly_linked_list<T>::operator!=(singly_linked_list<T>& L){
	return !(*this==L);
}




#endif