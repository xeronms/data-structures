#include "binary_tree.h"


binary_tree::binary_tree(){
	root = NULL;
}
binary_tree::binary_tree(binary_tree& T){
	root = T.root;
}

void binary_tree::insert(node& z, node* tmp){
	if ( z.key >= tmp->key){
		if ( (tmp->right) != NULL )
			insert(z, tmp->right);
		else
			tmp->right = new node(z);
	}
	else if ( z.key < tmp->key ){
		if ( (tmp->left) != NULL )
			insert(z, tmp->left);
		else
			tmp->left= new node(z);
	}
}

void binary_tree::insert(node& z){
	if (root != NULL)
		insert(z, root);
	else 
		root = new node(z);
}


void binary_tree::walk(node* a){
	if ( a != NULL ){
		walk(a->right);
		printf("%d\n", a->key);
		walk(a->left);
	}
}

void binary_tree::walk(){
	walk(root);
}

