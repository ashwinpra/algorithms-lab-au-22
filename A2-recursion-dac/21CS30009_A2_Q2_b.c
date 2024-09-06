/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>

/* a. O(NlogN) approach: 
	- Keep track of cumulative sum of the array  
	- Traverse through each element of the array and through binary search find a corresponding element
	  in the array, making use of the cumulative sum array such that sum is maximum under the constraints
	  that the number of partitions must be maintained and the minimum should be maximised
*/ 

// int getMax(int *w, int* cum_sum, int n_c, int n_f){



// 	// Reaches here if no other path returned anything, i.e., it is not possible to divide
// 	return -1;
// }

int main()
{
	// Taking user input for no. of friends, no. of chicken pieces, and weight of each chicken piece 

	int n_f;
	printf("Enter the number of friends: ");
	scanf("%d",&n_f);

	int n_c;
	printf("Enter number of chicken pieces: ");
	scanf("%d", &n_c);

	int weights[n_c];
	printf("Enter the consecutive weights (in grams) of the pieces: ");
	for(int i=0;i<n_c;i++) scanf("%d",&weights[i]);

	int cum_sum[n_c];
	for(int i=0;i<n_c;i++) {
		cum_sum[i] = i==0 ? weights[0] : cum_sum[i-1] + weights[i] ;
	}


	// int wt = getMax(weights,n_c,n_f);
	
	// (wt == -1) ? printf("Cannot be divided\n") : 
	// 			printf("Maximum weight of chicken piece(s) that you will get is: %d grams",wt);

	return 0;
}