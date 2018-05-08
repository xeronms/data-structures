#ifndef D_L_LIST_H
#define D_L_LIST_H

#include "singly_linked_list.h"



template<typename T>
class doubly_linked_list : public singly_linked_list<T> {

protected:

	element<T> *tail;


public:

	doubly_linked_list() : singly_linked_list<T>(), tail(NULL) {}
	
	void push(T& e);
	T pop();
	T back();
	T previous();

};




template<typename T>
void doubly_linked_list<T>::push(T& e){

	element<T>* node;
	node = new element<T>(e);

	if (head == NULL){ // adding 1st element to list
		tail = node;
	}
	else{
		node->next = head;
		head->prev = node;
	}
	head = node;
	++l_size;
}


template<typename T>
T doubly_linked_list<T>::pop(){
	
	element<T>* tmp;
	T data = *head->data;

	tmp = head->next;
	head->next->prev = NULL;
	delete head;
	head = tmp;
	--l_size;

	return data;
}


template<typename T>
T doubly_linked_list<T>::back(){
	i = l_size;
	return *head->data;
}


template<typename T>
T doubly_linked_list<T>::previous(){
	element<T>* e = head;
	
	for (int j=0; j<i; ++j){
		e = e->next;
	}
	
	++i;
	return *e->data;
}



#endif