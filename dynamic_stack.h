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
		case 0:
			tab = (T**) malloc (lim*sizeof(T*));
		case lim-1:

		default:
			break;
		}
		tab[top++] = e;
	}

	T pop();
	bool is_empty() const;
};


int add(void* element, Stos*stos){
	if (stos->top == MAX) return 0;
	if (stos->top == 0){
		stos->tab = (void**) malloc (stos->lim*sizeof(void*));
	}
	else if ((stos->top) > (stos->lim)){
		stos->lim += 10;
		stos->tab = (void**) realloc (stos->tab, stos->lim*sizeof(void*));
	}
	stos->tab[stos->top] = element;
	++(stos->top);
	return 1;
}

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

#endif