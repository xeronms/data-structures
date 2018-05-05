#ifndef S_L_LIST_H
#define S_L_LIST_H

template<typename T>
class element{
public:
		T* data;
		element* next;

		element():next(NULL), data(NULL){}
		element(T& a):data(&a),next(NULL){}

};



template<typename T>
class singly_linked_list {

	element<T> *head;
	//element<T> *tail;
	int l_size;

public:
	singly_linked_list():head(NULL), l_size(0){}
	
	
	void push(T& e);
	T pop();
	//const T& search(const element<T>&) const;
	void clear();
	T front()const;
	T next()const;
	int size()const{ return l_size;}
	bool operator==(const element<T>& )const;
	bool operator!=(const element<T>& )const;
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


template

#endif