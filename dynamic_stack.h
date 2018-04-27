#ifndef DYN_STACK_H
#define DYN_STACK_H
#include <stdlib.h>

struct size_err{};

template<typename T, int MAX_SIZE, int LIMIT_N>
class Stack{
	T** tab;
	int top;
	int lim; // after every amount of LIMIT_N elements added we extend the memory of the stack for another LIMIT_N of elements
public:
	Stack():top(0),lim(LIMIT_N){}
	~Stack(){
		//free
	}

	void push(const T& e){
		switch (top)
		{
		case MAX_SIZE:
			throw size_err();
			break;
		case 0:
			tab = (T**) malloc (lim*sizeof(T*));
			break;
		case lim:
			lim += LIMIT_N;
			tab = (T**) realloc (tab, lim*sizeof(T*));
			break;	
		default:
			break;
		}
		tab[top++] = e;
	}

	T pop();
	bool is_empty() const;
};

/*
int pop(Stos*stos){
	if (stos->top == 0)
		return 0;

	if (stos->top == 1)
		free(stos->tab);


	--(stos->top);

	if (stos->top < stos->lim-10){
		stos->lim -= 10;	
		stos->tab = (void**) realloc (stos->tab, (stos->lim*sizeof(void*)));
	}
	return 1;
}
*/
#endif