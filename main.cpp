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

		std::cout << *S1.stack_top() << std::endl;

		for ( Stack<int,1000,20>::iterator s_it = S1; s_it; ++s_it ){
			printf("%d\t",*s_it);
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

	for(doubly_linked_list<double>::iterator it2 = L3; it2; it2++){ // przejscie po liscie za pomoca iteratora, it++
		printf("%lf\n",*it2);
	}
	

	Stack<int,100,10> stack;
	int stack1=3, stack2=5 ;
	stack.push(stack1);
	stack.push(stack2);
	stack.pop();


	//printf("%d\n", C[3]);

	container<int> C2;
	
	C2.push_back(1);
	C2.push_back(1);
	C2.push_back(0);
	C2.push_back(1);
	C2.push_back(1);
	C2.push_back(0);
	C2.push_back(0);
	C2.push_back(0);
	C2.push_back(1);
	C2.push_back(1);
	C2.pop_back();
	for (int ii=0; ii<10; ++ii){
		printf("index %d : %d\n",ii, C2[ii]);
	}
	for(container<int>::iterator itt = C2; itt; ++itt){ // przejscie po liscie za pomoca iteratora, ++it
		printf("%d\n",*itt);
	}

	return 0;
}