/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdio.h>

// Utility function to compute the maximum of two numbers
#define max(x,y) (x>y?x:y)

/*
	Approach: 

		Start from the last day and check: 
			- If limit of 2nd site for that day is greater than the combined limit of 1st site 
			for that day + previous day => go for second website, and go 2 days behind
			(since you can only download from 2nd site if you dont download anything the previous day)
			- Else, go for first site, and go 1 day behind 

		I first implemented this approach recursively, then optimized it by memoizing repeating results
*/ 

// Optimised solution with DP 
// Note: size[i] stores the maximum size that can be downloaded in i days
int solveDP(int* lim1, int* lim2, int days, int* size){

	// Base case
	if(days<=0) return 0;

	// Checking if required answer is there in memo
	if(size[days]!=-1) return size[days];

	if(lim2[days]>lim1[days]+lim1[days-1]){
		// we will go for second website 
		// store in memo, and then return it
		size[days] = solveDP(lim1,lim2, days-2,size) + lim2[days];
		return size[days];
	}
	else{
		// we will go for first website
		// store in memo, and then return it
		size[days] = solveDP(lim1,lim2,days-1,size) + lim1[days];
		return size[days];
	}
}
	
int main()
{
	// Getting user input for number of days and daily limit of each site
	int days; 
	printf("Enter the number of days: ");
	scanf("%d",&days);

	// Using 1-indexed arrays for convenience
	int lim_1[days+1], lim_2[days+1];

	lim_1[0] = 0, lim_2[0]=0;	

	printf("Enter the download size restrictions of the first website (in GB): ");
	for (int i=1;i<=days;i++) scanf("%d",&lim_1[i]);

	printf("Enter the download size restrictions of the second website (in GB): ");
	for (int i=1;i<=days;i++) scanf("%d",&lim_2[i]);

	int size[days+1]; // memo array for DP
	// pre filling the array with -1 
	for(int i=0;i<=days;i++) size[i] = -1;

	// Calling DP function to get the maximum size, and then displaying it
	int max_size = solveDP(lim_1,lim_2,days,size);

	printf("Maximum possible download size is %d GB\n", max_size);

	return 0;
}