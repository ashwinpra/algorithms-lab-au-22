/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdio.h>

/*
	Approach: 
		- Create an array of size m*n+1 (1-indexed) and store all the index sums in it 
		- Convert this into a min-heap
		- Pop the heap k times, and each time, print the top value - this would display the minimum k index sums
*/

// global variable to keep track of size of heap
int size = 0;

// utility functions for heap
int root() {return 1;}
int parent(int n) {return n/2;}
int leftChild(int n) {return 2*n;}
int rightChild(int n) {return 2*n+1;}
int isNode(int n) {return n<=size;}
int hasParent(int n) {return n!=root();}

// utility function to swap two integers
void swap(int *a, int *b){
	int temp = *a; 
	*a = *b; 
	*b = temp;
}

// shiftUp function which is used while pushing
// Here the conditions are the ones required to create min-heap
void shiftDown(int *H, int n){

	while(isNode(leftChild(n))){
		int child = leftChild(n);

		if(isNode(rightChild(n)) && H[rightChild(n)]<H[leftChild(n)])
			child = rightChild(n);

		if(H[n]>H[child]) swap(&H[n],&H[child]);
		else break;

		n = child;
	}
}

// Function to pop the root of the heap
void pop(int *H){
	H[root()] = H[size--];
	shiftDown(H,root());
}


// Function to create a heap (here: min-heap) from a given array
// Here we are converting the same array to a min-heap
void heapify(int *H, int n){

	size = n;
	// now shift down starting from last node with a child, till root
	for(int i=size/2;i>=1;i--) shiftDown(H,i);

}

// Function that solves and prints the k minimum index sums
void solve(int *arr1, int *arr2, int* H, int m, int n,int k){

	int H_idx=1; // to make H a 1-indexed array

	// storing all the index sums in H
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			H[H_idx++] = arr1[i]+arr2[j];
		}
	}

	// now that we have the array of all index sums, we will convert it to a min heap and pop the first k elements

	heapify(H,m*n);

	int t=0;
	while(t<k){

		/* repeat the following k times: 
			get the value at the root (top) which will be the minimum 
			pop the heap
			print "top"
		*/
		int top = H[root()];
		pop(H);
		printf("%d ",top);
		t++;
	}
	printf("\n");

}

int main()
{	
	// Hardcoded arrays and value "k"

	int m = 64;
	int arr1[] = {647,225,200,137,823,241,923,173,633,797,203,797,820,789,338,72,274,407,577,306,167,928,40,417,86,751,384,697,144,986,665,468,225,121,372,143,86,737,86,4,557,874,341,628,148,748,852,212,50,656,681,153,353,824,8,176,783,993,559,970,936,399,61,882};

	int n = 60;
	int arr2[] = {206,354,757,547,700,623,14,623,514,646,194,444,414,849,125,566,202,948,292,96,732,285,374,702,940,772,762,737,974,559,620,898,631,96,445,331,437,177,672,951,822,866,395,955,715,520,240,636,187,532,731,637,535,823,339,475,314,819,931,7};

	int k = 10;

	int A[m*n+1]; // heap array that will store index sums

	solve(arr1,arr2,A,m,n,k);

	return 0;
}