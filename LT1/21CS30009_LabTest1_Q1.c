/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include <stdio.h>

// Utility function to swap two numbers through pointers
void swap(int *a, int *b){
	int temp = *a; 
	*a = *b; 
	*b = temp;
}

// Function to partition the array
int partition(int* A, int p, int r){
	int pivot = p;
	int start = p+1;
	int end = r;

	while(start<end){
		// Traversal is done until two elements are found: one at the left but higher than pivot, one at the right but lower than pivot
		while(A[start]<=A[pivot]) start++;
		while(A[end]>A[pivot])end--;

		// Terminating when ends meet
		if(start==end) break;

		// If start is lower than end, elements are swapped
		if(start<end)
			swap(&A[start],&A[end]);
	}
	// Finally pivot element is started with end element and its index is returned
	swap(&A[pivot],&A[end]);
	return end;

}

// Main function for modified quicksort
void modified_quicksort(int* A, int p, int r){
	if(p<r){
	int q = partition(A,p,r);
	// Algorithm is run again on both halves 
	modified_quicksort(A,p,q-1);
	modified_quicksort(A,q+1,r);
	}
}

int main(int argc, char const *argv[])
{	
	// Taking size of array and the array itself as user input 

	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);

	int a[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	// Sorting the array
	modified_quicksort(a,0,n-1);

	// Displaying sorted array
	printf("Sorted sequence: ");
	for(int i=0;i<n;i++) printf("%d ",a[i]);


	return 0;
}