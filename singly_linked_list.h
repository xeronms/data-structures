#ifndef S_L_LIST_H
#define S_L_LIST_H

template<typename T>
class element{
public:
		T* data;
		element* next;

		element():next(NULL), data(NULL){}
		element(T& a):data(&a),next(NULL){}

		~element(){	delete next; delete data;}
};



template<typename T>
class singly_linked_list {

	element<T> *head;
	element<T> *tail; //
	int l_size;

public:
	singly_linked_list():head(NULL), tail(NULL), size(0){}
	~singly_linked_list(){	delete head; delete tail;}
	
	void push(T& e);
	T pop();
	//const T& search(const element<T>&) const;
	void clear();
	T front();
	T next();
	int size(){ return l_size;}
	bool operator==();
	bool operator!=();
};

template<typename T>
void singly_linked_list<T>::push(T& e){
	element<T>* node;
	node = 
}


#endif