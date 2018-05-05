#include "binary_tree.h"
#include "dynamic_stack.h"
#include "singly_linked_list.h"
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
		}
	}
	catch (Exception){std::cout << "ERR"<< std::endl;}


	singly_linked_list<int> L1;
	int t =20, r = 10, s= 15;
	L1.push(t);L1.push(r);L1.push(s);
	printf("%d\n",L1.pop());
	L1.clear();
	printf("%d\n",L1.size());

	return 0;
}