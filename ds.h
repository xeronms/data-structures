#ifndef data_structures
#define data_structures

#include <iostream>

class node{
	int key;
	node *left;
	node *right;
	//node *p;
public:
	node(){}
	node(int a):key(a),left(NULL),right(NULL){}
	node(node& a):key(a.key),left(a.left),right(a.right){}
};

class binary_tree{
	node root;

public:
	binary_tree();
	binary_tree(binary_tree&);
	void insert(node z);
};

#endif