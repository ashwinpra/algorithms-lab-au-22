/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>

/*
	Approach: 
		Starting with an empty hash table, the elements of A are hashed into it, with the value corresponding to the freuqnecy of the element 
		Now correspondingly, the elements of B are removed from the hash table
		If A and B contain the same set of numbers, these 2 operations would result in an empty hash table again
		This condition can be used to check whether they have the same set of numbers
*/


// Node that will be used in hash table, stores key (ie the value itself), and its frequency in the array 
typedef struct{
	int key;
	int freq; 
}node;

// Function to insert each element of A into the hashtable, along with their frequencies
void insertA(node* hashtable, int* A, int n){

	for(int i=0;i<n;i++){
		// Choosing each element of A as key and finding its corresponding index
		int key = A[i];
		int index = key%n;

		// Following linear probing, approppriate position for "key" is obtained and it is hashed
		while(hashtable[index].key!=key && hashtable[index].key!=-1) index++;

		hashtable[index].key = key; 
		hashtable[index].freq++;
	}
}

// Function to remove each element of B from the hashtable
// It is the same as the above function, except that frequency is reduced (to denote removal)
void removeB(node* hashtable, int* B, int n){
	for(int i=0;i<n;i++){
		int key = B[i];
		int index = key%n;

		while(hashtable[index].key!=key && hashtable[index].key!=-1) index++;

		hashtable[index].key = key; 
		hashtable[index].freq--;
	}
}
	
// Function to check whether the arrays A and B contain the same elements

int checkEqual(int* A, int * B, node* hashtable, int n){
	insertA(hashtable,A,n);

	removeB(hashtable,B,n);

	// After hashing elements of A and then removing elements of B, it is checked whether the hash table is empty (all frequencies = 0)
	// If not, 0 is returned to denote that it is not empty
	for(int i=0;i<n;i++) {
		if(hashtable[i].key!=-1 && hashtable[i].freq!=0) return 0;
	}

	return 1;
}


int main()
{	
	// Taking user input for size of arrays and corresponding arrays
	int n; 
	printf("Enter size of arrays: ");
	scanf("%d",&n);

	int A[n],B[n];

	printf("Enter elements of array A: ");
	for(int i=0;i<n;i++) scanf("%d",&A[i]);

	printf("Enter elements of array B: ");
	for(int i=0;i<n;i++) scanf("%d",&B[i]);

	// Making hash table and prefilling it approppriately
	node hashtable[n];
	for (int i=0;i<n;i++) {
		hashtable[i].key=-1;
		hashtable[i].freq=0;
	}

	// Finally, displaying answer based on the result of the checkEqual function
	int ans  = checkEqual(A,B,hashtable,n);

	if(ans) printf("Both arrays have the same set of numbers\n");

	else printf("Both arrays have different set of numbers\n");
	
	return 0;
}