#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
	void** tab;
	int top;
	int lim;
} Stos;

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

int main(){
	int i;
	Stos stos;
	stos.top = 0;
	stos.lim = 10;

	//przykladowe dzialania
	if(pop(&stos)==0) puts("empty");
	for (i=0; i<101; ++i){
		if(add(&i, &stos)==0) puts("overload");
	}
	for (i=0; i<23; ++i){
		if(pop(&stos)==0) puts("empty");
	}
	printf("top=%d lim=%d\n", stos.top, stos.lim);
	


	if (stos.top) free(stos.tab);
	return 0;
}