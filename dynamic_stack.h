#ifndef DYN_STACK_H
#define DYN_STACK_H
#include <stdlib.h>

struct size_err{};
struct empty_err{};
//enum errors {size_err,empty_err};

template<typename T, int MAX_SIZE, int LIMIT_N>
class Stack{
	T** tab;
	int top;
	int lim; // after every amount of LIMIT_N elements added we extend the memory of the stack for another LIMIT_N of elements
public:
	Stack():top(0),lim(LIMIT_N){
		tab = (T**) malloc (lim*sizeof(T*));
	}
	~Stack(){
		free(tab);
	}
	
	void push(T& e){ //const?
		if (top==MAX_SIZE) throw size_err();
		
		if (top==lim){
			lim += LIMIT_N;
			tab = (T**) realloc (tab, lim*sizeof(T*));
		}

		tab[top++] = &e;
	}

	T pop(){
		if (is_empty()) throw empty_err();// or return T();
		if (top == lim-LIMIT_N){
			lim -= LIMIT_N;	
			tab = (T**) realloc (tab, (lim*sizeof(T*)));
		}

		return *tab[--top];
	}

	bool is_empty() const{
		return !top;
	}
};

#endif