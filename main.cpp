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
	Stack<int,1000,20> S1;
	int t[1000];
	for (int j=0; j<1000; ++j){
		t[j] = j+1;
		S1.push(t[j]);
	}
	for (int j=0; j<590; ++j){
		S1.pop();
	}}
	catch (size_err){std::cout << "ERR"<< std::endl;}
	catch (empty_err){std::cout << "ERR"<< std::endl;}
	return 0;
}