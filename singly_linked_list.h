#ifndef S_L_LIST_H
#define S_L_LIST_H

template<typename T>
class element{
		T data;
		element* next;
	};


template<typename T>
class singly_linked_list {
	element* head;
	element* tail;

public:

	void push(const T& e);
	T pop();
	const T& search(const element&) const;

};


#endif