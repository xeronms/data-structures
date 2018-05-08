#include "binary_tree.h"
#include "dynamic_stack.h"
#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include <iostream>



int main(){ //przykladowe dzialania

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
	printf("%d\n",L1.pop());L1.next();
	printf("%d\n",L1.next());
	L1.clear();

	singly_linked_list<int> L2;
	L2.push(s);
	printf("%d\n",L2!=L1);


	doubly_linked_list<double> L3;
	double t2 =20, r2 = 10, s2= 15;
	L3.push(t2);L3.push(r2);L3.push(s2);
	return 0;
}