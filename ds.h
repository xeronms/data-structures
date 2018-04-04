#ifndef data_structures
#define data_structures

#include <iostream>

struct node{
public:
	int key;
	node *left;
	node *right;
	//node *p;
	node():key(NULL),left(NULL),right(NULL){}
	node(int a):key(a),left(NULL),right(NULL){}
	node(node& a):key(a.key),left(a.left),right(a.right){}
};

class binary_tree{
	node *root;

public:
	binary_tree();
	binary_tree(binary_tree&);
	void insert(node &,node *);
	void insert(node&);
	void walk();
	void walk(node *);
};

#endif