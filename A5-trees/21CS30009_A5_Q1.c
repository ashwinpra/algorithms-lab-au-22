/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdio.h>
#include<stdlib.h>

/*
	Approach: 
	1. First traverse through the tree in "In order" fashion and enqueue them in a queue of nodes in that order
	2. Dequeue this queue to get the first node in "In order" fashion 
	3. Again traverse through the tree in "In order" fashion to assign the corresponding "inOrderSuccesor" node of every node
	4. Starting from the first node mentioned in point 2, traverse through the nodes using the "inOrderSuccesor" pointer, while printing them 
*/

// making node structure for tree

typedef struct _node{
	int key; 
	struct _node* left;
	struct _node* right;
	struct _node* inOrderSuccessor;
}node;

// making a queue structure along with required helper functions

typedef struct{
	node* nodes[100];
	int bottom;
	int top; 
}queue;

int isEmpty(queue* q){
	return q->top<q->bottom;
}

void enqueue(queue* q, node* node){
	q->top++;
	q->nodes[q->top]=node;
}

node* dequeue(queue* q){
	q->bottom++;
	return q->nodes[q->bottom-1];
}

// Function to create a new node by dynamic memory allocation, and assigning a value to it
node* createNode(int value){
	node* newnode = (node*) malloc(sizeof(node));

	newnode->key = value;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->inOrderSuccessor = NULL;

	return newnode; 
}

// Traversing the tree in order, and enqueueing the corresponding nodes
void makeInOrderQueue(node* node, queue* q){

	// base case 
	if(node==NULL) return;
	
	makeInOrderQueue(node->left,q); // L

	enqueue(q,node); // N
	
	makeInOrderQueue(node->right,q); // R

}

// In order successor of each node is assigned by dequeing the queue obtained aove
void assignSuccessors(node* node, queue* q){

	// base case
	if(node == NULL) return;

	assignSuccessors(node->left, q); // L

	if(!isEmpty(q)) node->inOrderSuccessor = dequeue(q); // N

	assignSuccessors(node->right, q); // R

}

// Starting from the first node in "in order" traversal, we traverse and print the keys of all the nodes using the "inOrderSuccesor" point
void printInOrderSuccessors(node* first){

	while(first->inOrderSuccessor!=NULL){
		 printf("In order successor of %d is %d\n",first->key,first->inOrderSuccessor->key);
		 first = first->inOrderSuccessor;
	}
}



int main()
{
	// Creating the binary tree given in question 	
	node* root = createNode(5);
	root->left = createNode(9);
	root->right = createNode(7);
	root->left->left = createNode(3);
	root->right->left = createNode(4);
	root->right->right = createNode(1);
	root->right->right->left = createNode(6);
	root->right->right->right = createNode(2);

	// Initialising queue that will store in order successors

	queue* q = (queue*)malloc(sizeof(queue));
	q->top = -1;
	q->bottom = 0;

	makeInOrderQueue(root,q); // Function that fills the queue with in order successor

	// Finding the first node that comes in "in order"
	node* firstInOrder = dequeue(q);
	
	// Using the queue, assigning in order successor for every node
	assignSuccessors(root,q);

	// Finally printing in order successors of all nodes
	printInOrderSuccessors(firstInOrder);

	return 0;
}