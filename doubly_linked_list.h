#ifndef D_L_LIST_H
#define D_L_LIST_H

#include "singly_linked_list.h"


/* 
	==================================================================

	klasa dziedziczy z singly_linked_list wiêc, zgodnie z zasad¹ DRY, nie ma koniecznoœci robienia nowego iteratora

	==================================================================
*/


template<typename T>
class doubly_linked_list : public singly_linked_list<T> {

protected:

	element<T> *tail;


public:

	doubly_linked_list() : singly_linked_list<T>(), tail(NULL) {}
	
	void push(const T& e);
	void push_back(const T& e);
	T pop();
	T pop_back();
	element<T>* back() const;
	element<T>* previous(element<T>* ) const;
	element<T>* previous() const;

};




template<typename T>
void doubly_linked_list<T>::push(const T& e){

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
void doubly_linked_list<T>::push_back(const T& e){

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
typename doubly_linked_list<T>::element<T>* doubly_linked_list<T>::back() const{
	return tail;
}


template<typename T>
typename doubly_linked_list<T>::element<T>* doubly_linked_list<T>::previous(typename doubly_linked_list<T>::element<T>* e) const{
	return e.prev;
}


template<typename T>
typename doubly_linked_list<T>::element<T>* doubly_linked_list<T>::previous() const{
	return back();
}


/*
template<>
class doubly_linked_list<*bool> : doubly_linked_list<*void>{
	
};
*/

#endif