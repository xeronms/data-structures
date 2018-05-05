#ifndef S_L_LIST_H
#define S_L_LIST_H

template<typename T>
class element{
public:
		T* data;
		element* next;
		element():next(NULL), data(NULL){}
		/*element(const element& a){
			data = a.data;
			next = a.next;
		}*/
		~element(){	delete next; delete data;}
};



template<typename T>
class singly_linked_list {

	element<T> *head;
	element<T> *tail;

public:
		singly_linked_list():head(NULL), tail(NULL){}
		~singly_linked_list(){	delete head; delete tail;}

	void push( T& e){
		element<T> x;
		x.data = &e;
		x.next = head;
		//
		head =  &x;
		//
	}

	T pop();
	const T& search(const element<T>&) const;

};


#endif