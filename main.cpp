#include "binary_tree.h"
#include "dynamic_stack.h

int main(){
	node a(5);
	node b(8);
	node c(2);
	binary_tree T1;

	T1.insert(a);
	T1.insert(b);T1.insert(c);
	T1.walk();
	return 0;
}