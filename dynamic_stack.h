#ifndef DYN_STACK_H
#define DYN_STACK_H
#include <stdlib.h>

struct Exception { };
struct size_err : public Exception { };
struct empty_err : public Exception { };


template<typename T, int MAX_SIZE, int LIMIT_N>
class Stack{

	T* tab;
	int top;
	int lim; // after every amount of LIMIT_N elements added we extend the memory of the stack for another LIMIT_N of elements


public:

	Stack():top(0),lim(LIMIT_N){
		tab = (T*) malloc (lim*sizeof(T));
	}

	~Stack(){
		free(tab);
	}
	


	void push(T& e){ //const?

		if (top==MAX_SIZE) throw size_err();
		
		if (top==lim){
			lim += LIMIT_N;
			tab = (T*) realloc (tab, lim*sizeof(T));
		}

		tab[top++] = e;
	}


	T pop(){

		if (is_empty()) throw empty_err();// or return T();
		if (top == lim-LIMIT_N){
			lim -= LIMIT_N;	
			tab = (T*) realloc (tab, (lim*sizeof(T)));
		}

		return tab[--top];
	}


	bool is_empty() const{
		return !top;
	}


	int size() const{
		return top;
	}


	T* stack_top() const{
		return &tab[top-1];
	}
	


	class iterator{

		T* current;
		Stack<T, MAX_SIZE, LIMIT_N>& st;

	public:

		iterator(Stack<T, MAX_SIZE, LIMIT_N>& s): st(s), current(s.tab){}
		
		iterator(iterator& it): st(it.st), current(it.current){} //konstr. kopiujacy, potrzebny do operator++(int)

		iterator& operator++(){
			if( current ) ++current;
			return *this;
		}

		iterator operator++(int){
			iterator it(*this);

			if ( current ){	
				++current;
			}
			return it;
		}

		T operator*(){
		
			return *current;
		}

		operator bool() const{
			
			return current < st.stack_top();
		}
	};
};

/*
template<int MAX_SIZE, int LIMIT_N>
class Stack<bool, MAX_SIZE, LIMIT_N>{

	char* tab;
	int top;
	int lim; // after every amount of LIMIT_N elements added we extend the memory of the stack for another LIMIT_N of elements
	int bool_index;

public:

	Stack():top(0),lim(LIMIT_N), bool_index(0){
		tab = (char*) malloc (lim*sizeof(char));
	}

	~Stack(){
		free(tab);
	}
	


	void push(bool& e){ 

		if (top==MAX_SIZE) throw size_err();
		
		if (top==lim){
			lim += LIMIT_N;
			tab = (char*) realloc (tab, lim*sizeof(char));
			bool_index = 0;
		}


		tab[top-1] += (e << (bool_index++));

		if (bool_index == 8){
			++top;
			bool_index = 0;
		}
	}


	bool pop(){

		if (is_empty()) throw empty_err();// or return T();
		if (top == lim-LIMIT_N){
			lim -= LIMIT_N;	
			tab = (char*) realloc (tab, (lim*sizeof(char)));
		}

		bool b = *this[bool_index-1];

		--bool_index;

		if (bool_index == 0){
			--top;
			bool_index = 8;
		}

		return b;
	}


	bool is_empty() const{
		return !top;
	}


	int size() const{
		return top;
	}


	char* stack_top() const{
		return &tab[top-1];
	}
	


	inline bool operator[](int i) const {
		return (tab[top-1] >> i) % 2;
	}



};
*/
#endif