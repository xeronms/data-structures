#include "binary_tree.h"
#include "dynamic_stack.h"
#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include "container.h"
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
	int t =20, r = 10, s= 15, sg =2;
	L1.push(t);L1.push(r);L1.push(s);

	

	for(singly_linked_list<int>::iterator it = L1; it; ++it){ // przejscie po liscie za pomoca iteratora, ++it
		printf("%d\n",*it);
	}


	singly_linked_list<int> L2;
	L2.push(sg);
	L2==L1;

	

	doubly_linked_list<double> L3;
	double t2 =20, r2 = 10, s2= 15;
	L3.push(t2);L3.push(r2);
	L3.pop();L3.push_back(s2);

	for(doubly_linked_list<double>::iterator it = L3; it; it++){ // przejscie po liscie za pomoca iteratora, it++
		printf("%lf\n",*it);
	}


	container<int> tab(0);
	int a2=5, b2=4;
	tab.push_back(a2); tab.push_back(b2);tab.pop_back();




	return 0;
}