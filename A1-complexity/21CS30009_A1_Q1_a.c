/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdio.h>

int main(){
	// Taking no. of cities and population as input
	int n;
	printf("Enter the number of cities: ");
	scanf("%d",&n);

	int pop[n];
	printf("Enter the populations: ");
	for(int i=0;i<n;i++){
		scanf("%d",&pop[i]);
	}

	/* Brute force solution -> O(N^2): 
		Iterating through each element of the array and further iterating to find a 
		corresponding element such that i<j, Wi<Wj, and finding the maximum possile (j-i)
		out of all of these element pairs
	*/

	int max_diff = -10000;

	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(pop[j]>pop[i] && j-i > max_diff) max_diff=j-i;
		}
	}

	max_diff = -10000 ? printf("None\n") : printf("Maximum number of hops required: %d\n",max_diff);

	return 0;
}


