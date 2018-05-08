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
	void push_back(T& e);
	T pop();
	T pop_back();
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
void doubly_linked_list<T>::push_back(T& e){

	element<T>* node;
	node = new element<T>(e);

	tail->next = node;
	node->prev = tail;
	tail = node;

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
T doubly_linked_list<T>::pop_back(){

	element<T>* tmp = tail->prev;
	T data = *tail->data;

	tmp->next = NULL;
	
	delete tail;
	tail = tmp;

	return data;
}


template<typename T>
T doubly_linked_list<T>::back(){
	i = l_size;
	return *tail->data;
}


template<typename T>
T doubly_linked_list<T>::previous(){
	element<T>* e = tail;
	
	if (i!=0){
		--i;

		for (int j=l_size; j>i; --j){
			e = e->prev;
		}
	}

	return *e->data;
}



#endif