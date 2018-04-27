#include "binary_tree.h"
#include "dynamic_stack.h"
#include <iostream>

int main(){
	node a(5);
	node b(8);
	node c(2);
	binary_tree T1;

	T1.insert(a);
	T1.insert(b);T1.insert(c);
	T1.walk();


	try{
	Stack<int,1000,2> S1;
	int t[110];
	for (int j=0; j<110; ++j){
		t[j] = j+1;
		S1.push(t[j]);
		printf("%d %d",*S1.tab[j],S1.is_empty());
		
	}S1.pop();
	}
	catch (errors){std::cout << "ERR"<< std::endl;}

	return 0;
}