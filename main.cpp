#include "binary_tree.h"
#include "dynamic_stack.h"


int main(){
	node a(5);
	node b(8);
	node c(2);
	binary_tree T1;

	T1.insert(a);
	T1.insert(b);T1.insert(c);
	T1.walk();

	Stack<int,1000,50> S1;
	int t[110];
	for (int j=0; j<110; ++j){
		t[j] = j+1;
		S1.push(t[j]);
		printf("%d",t[j]);
	}
	

	return 0;
}