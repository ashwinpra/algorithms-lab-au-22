/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>

/* a. Brute Force approach: 
	- We make partitions in the array -> Total no. of partitions = Total people - 1 
	- All such partitioned arrays are taken, and we choose the one whose minimum 
	valued sum is the highest
*/ 


typedef struct{
	int* partitions;
}partition;

void placePartitions(int *w, int n_f, int n_c, partition* return_parts{
	/*
	 each partition is assumed to be placed after a certain index
	 when no. of partitions left is "n_p", the maximum index after which partition can 
	 be placed is n_c-n_p
	 */
	partition parts[100];
	int n_p = n_f;

	for(int i=0;i<n_p;i++){
		int idx = 0;
		// we are placing ith partition
		for(int j=0;j<n_c;j++){
			parts[idx++][i] = j;
		}
	}
	return_parts=&parts;
}


int main()
{
	// Taking user input for no. of friends, no. of chicken pieces, and weight of each chicken piece 
	
	int n_f;
	printf("Enter the number of friends:");
	scanf("%d",&n_f);

	int n_c;
	printf("Enter number of chicken pieces:");
	scanf("%d", &n_c);

	int weights[n_c];
	printf("Enter the consecutive weights (in grams) of the pieces:");
	for(int i=0;i<n_c;i++) scanf("%d",&weights[i]);

	// int wt = ;
	//printf("Maximum weight of chicken piece(s) that you will get is: %d grams",wt);

	return 0;
}