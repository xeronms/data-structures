#ifndef S_L_LIST_H
#define S_L_LIST_H

template<typename T>
class element{

		T& data;
		element* next;
};



template<typename T>
class singly_linked_list {

	element<T> *head;
	element<T> *tail;

public:

	void push(const T& e){
		element<T> x;
		x.data = e;
		x.next = head;
		//
		head =  x;
		//
	}

	T pop();
	const T& search(const element<T>&) const;

};


#endif