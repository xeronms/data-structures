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


	


	class iterator{

		T* current;
		Stack<T, MAX_SIZE, LIMIT_N>& st;

	public:

		iterator(Stack<T, MAX_SIZE, LIMIT_N>& s): st(s), current(s.tab){}
		
		iterator(iterator& it): st(it.st), current(it.current){} //konstr. kopiujacy, potrzebny do operator++(int)

		iterator& operator++(){
			if( current ) current = ++st.tab;
			return *this;
		}

		iterator operator++(int){
			iterator it(*this);

			if ( current ){	
				current = ++st.tab;
			}
			return it;
		}

		T operator*(){
		
			return *current;
		}

		operator bool() const{
			
			return current != &st.tab[st.top-1];
		}
	};
};

#endif