/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdio.h>
#include<stdlib.h>


/*
	Approach: 
	1. Assign level number to each of the nodes
	2. Find and store all the leaf nodes
	2. Iterate through the leaves, and for every node, calculate the no. of hops required to reach 
	from the leaf to the node (-1 if its not reachable) and store this in an array
	3. Iterate through this array, and display in the format required

	Assumptions: Max number of nodes = 100, Maximum value of a certain node = 100
*/

#define max(a,b) (a>b?a:b)

typedef struct _node{
	int key; 
	struct _node* left;
	struct _node* right;
}node;

typedef struct{
	node* leafnode;
}leaf;


node* createNode(int value){
	node* newnode = (node*) malloc(sizeof(node));

	newnode->key = value;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode; 
}

int contains(node* node, leaf* leaves){
	for(int i=0;i<100;i++){
		if(leaves[i].leafnode==node) return 1;
	}
	return 0;
}

void insert(node* node, leaf* leaves){
	if(contains(node,leaves)) return;

	int i=0;
	while(leaves[i].leafnode!=NULL) i++;

	leaves[i].leafnode=node;
}

void getLeaves(node* root, leaf* leaves){

	// base cases 
	if(root==NULL) return;

	if(root->left==NULL && root->right == NULL){
		insert(root,leaves);
	}

	getLeaves(root->left,leaves);
	getLeaves(root->right,leaves);
}

// Checks if a certain subtree contains the required node
int containsLeaf(node* root, node* leaf){

	// base cases
	if(root==leaf) return 1;
	if(root==NULL) return 0;

	return (containsLeaf(root->left,leaf) || containsLeaf(root->right,leaf));
}



// Calculates the number of hops required to reach from a certain leaf to every node

int getHops(node* root, node* leaf,int index,int n_leaves,int hops[][n_leaves]){

	// base case
	if(root==NULL) return -2;

	if(root==leaf) return -1;

	if(containsLeaf(root->left)) {
		hops[root->key][index]=1+getHops(root->left)
		return hops[root->key][index]
	}
	else if(containsLeaf(root->right)) {
		hops[root->key][index]=1+getHops(root->right)
		return hops[root->key][index]
	}
 	
}


int main()
{	
	// Creating the binary tree given in question
	node* root = createNode(10);	
	root->left = createNode(7);
	root->right = createNode(2);
	root->left->left = createNode(11);
	root->left->left->right = createNode(17);
	root->right->left = createNode(5);
	root->right->right = createNode(16);
	root->right->right->left = createNode(9);
	root->right->right->right = createNode(21);

	int n_leaves=0;

	// Initialising array of leaves and prefilling their nodes with NULL
	leaf leaves[100];
	for(int i=0;i<100;i++) leaves[i].leafnode=NULL;

	// Using function to obtain the leaves and store them in array
	getLeaves(root,leaves); 
	
	// Getting no. of leaves as no. of non-NULL nodes
	for(int i=0;i<100;i++) {
		if(leaves[i].leafnode!=NULL) n_leaves++;
	}

	// Array to store hops required from each leaf to each node
	int hops[100][n_leaves];


	for(int i=0;i<n_leaves;i++){
		// for each leaf, calculate hops required for every node
		getHops(root,leaves[i].leafnode,i,n_leaves,hops);
	}
	

	return 0;
}