/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdio.h>

/*
	Approach: 
		- Make a max heap that will store the no. of sweets in each container
		- With the help of the max heap, do the following "k" times: 
			i. get the value at the root, which will be maximum
			ii. pop the heap 
			iii. since floor(top/2) is taken, the remaining, i.e. top - floor(top/2) is pushed pack into the array
		- After this, the heap will contain the remaining sweets in each container 
		- Add these up to get remaining total sweets
*/

// global variable to keep track of size of heap
int size = 0;

// utility functions for heap
int root() {return 1;}
int parent(int n) {return n/2;}
int leftChild(int n) {return 2*n;}
int rightChild(int n) {return 2*n+1;}
int isNode(int n) {return n<=size;}
int hasParent(int n){return n!=root();}

// utility function to swap two integers
void swap(int *a, int *b){
	int temp = *a; 
	*a = *b; 
	*b = temp;
}

// shiftUp function which is used while pushing
// Here the conditions have been modified to account for the fact that we are creating a max-heap
void shiftUp(int* H, int n){

	while(hasParent(n) && H[parent(n)]<H[n]){
		swap(&H[parent(n)],&H[n]);
		n = parent(n);
	}
}

// Function to push a value into the heap
void push(int* H, int val){
	H[++size]=val;
	shiftUp(H,size);
}

// shiftDown function which is used while popping
// Here the conditions have been modified to account for the fact that we are creating a max-heap
void shiftDown(int *H, int n){

	while(isNode(leftChild(n))){
		int child = leftChild(n);

		if(isNode(rightChild(n)) && H[rightChild(n)]>H[leftChild(n)])
			child = rightChild(n);

		if(H[n]<H[child]) swap(&H[n],&H[child]);
		else break;

		n = child;
	}
}

// Function to pop the root of the heap
void pop(int *H){
	H[root()] = H[size--];
	shiftDown(H,root());
}

// Function to create a heap (here: max-heap) from a given array
void heapify(int *a, int *H, int n){

	for(int i=0;i<n;i++) H[i+1]=a[i];
	size = n;

	// now shift down starting from last node with a child, till root
	for(int i=size/2;i>=1;i--) shiftDown(H,i);

}

// Function that solves and returns the remaining total sweets
int solve(int* a, int* H, int n, int k){

	heapify(a,H,n);
	// now we have a max heap "H"

	int i = 0; 
	while(i<k){

		/* repeat the following k times: 
			get the value at the root (top) which will be the maximum 
			pop the heap
			push the value top - floor(top/2) into the heap
		*/

		int top = H[root()];
		pop(H);
		int taken = top/2; // This much is taken by the person, the rest of it is pushed back into the heap
		push(H,top-taken);
		i++;
	}

	// now get the remaining total sweets by finding the sum of elements in the heap 
	int sum = 0;
	while(size>0){
		sum +=  H[root()];
		pop(H);
	}

	return sum;
}

int main()
{
	// Getting number of containers, no. of sweets in each container, and value of "k" from user

	int n; 
	printf("Enter number of containers: ");
	scanf("%d",&n);

	int containers[n];
	printf("Container = ");
	for(int i=0;i<n;i++) scanf("%d",&containers[i]);

	int k;
	printf("k = "); 
	scanf("%d",&k);

	int H[n+1]; // array that will act as max-heap

	// Getting the answer from "solve" function and displaying it
	int ans = solve(containers,H,n,k);
	printf("Remaining total sweets: %d\n",ans);

	return 0;
}