/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>
#include<stdlib.h>

/*
	Approach: 
		The tree is created based on its corresponding array (hard-coded) using the fact that the element at index "i" has children "2i+1" and "2i+2"
		Correspondingly, the levels of the nodes are also stored in the tree 

		Each level is enqueued in a queue (in an array of queues), and it is dequeued one-by-one to get the corresponding level order traversal

		Now using this queue, mirroring is done 

		We need to reverse the order of the elements in the odd levels

		So we can reverse the corresponding elements in the queue, and dequeue it and assign it to corresponding nodes
*/

// Node of tree
typedef struct _node{
	int key; 
	int level;
	struct _node* left;
	struct _node* right;
}node;

// Making a queue with struct and utility functions
typedef struct{
	node* nodes[100];
	int bottom;
	int top; 
}queue;

int isEmpty(queue* q){
	return q->top < q->bottom;
}

void enqueue(queue* q, node* node){
	q->top++;
	q->nodes[q->top]=node;
}

node* dequeue(queue* q){
	q->bottom++;
	return q->nodes[q->bottom-1];
}

void swap(node** a, node** b){
	node* temp  = *a;
	*a = *b;  
	*b = temp;
}

node* createNode(int value, int level){
	node* newnode = (node*) malloc(sizeof(node));

	newnode->key = value;
	newnode->level = level;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode; 
}

// Function to make binary tree from corresponding array representation
node* makeTree(int* tree, int n,int index,int level){

	if(index < n){
		node* root = createNode(tree[index],level);

		root->left = makeTree(tree,n,2*index+1,level+1);
		root->right = makeTree(tree,n,2*index+2,level+1);

		return root; 
	}
	else return NULL;

}

// Function to enqueue each level into a queue
void enqueueLevels(queue* q, node* root){

	if(root==NULL) return;

	enqueue(&q[root->level],root);

	enqueueLevels(q,root->left);
	enqueueLevels(q,root->right);
}

// Prints level order traversal
void levelOrderTraversal(queue* q, int q_size){
	for(int i=0;i<q_size;i++){
		queue qi = q[i];
		while(!isEmpty(&qi)) printf("%d ",dequeue(&qi)->key);
	}
}

node* mirror(queue* q, node* root){
	for(int i=1;i<q_size;i+=2){
		queue qi = q[i]; 
		// This queue corresponds to an odd level
		// It is hence mirrored 
		for(int j=qi.bottom;j<=(q.bottom+q.top)/2;j++){
			swap(qi.nodes[j],qi.nodes[j+q1.bottom+q1.top]);
		}

	}

	// Now this mirrored queue is dequeued and stored in the tree
	// NOTE: INCOMPLETE 
}

int main()
{	
	int tree_arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	node* root = makeTree(tree_arr,15,0,0);

	int q_size =4;

	// Prefilling top and bottom values of queue
	queue q[q_size];
	for(int i=0;i<q_size;i++){
		q[i].top = -1;
		q[i].bottom = 0;
	}

	enqueueLevels(q,root);

	printf("Before mirorring: \n");
	printf("Level order traversal: ");

	levelOrderTraversal(q,q_size);

	return 0;
}