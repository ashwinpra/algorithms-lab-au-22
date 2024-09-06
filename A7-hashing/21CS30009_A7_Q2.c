/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>

/*
	Approach: 
		- Make a hash table that will store the losses of every team as value 
		- It will be a 1-indexed array of size = no. of teams+1, and
		the i-th index stores the no. of losses of team no. "i"
		- From this hash table, we will then find all "i" such that:
			- hash_table[i] = 0 (teams with no losses)
			- hash_table[i] = 1 (teams with exactly one loss) 

		- These "i" values are also the corresponding team numbers that we require (since we hashed it in that way)
*/

int main()
{
	// Taking no. of teams, no. of matches and results from user as input

	int n_teams;
	printf("Enter the number of teams: ");
	scanf("%d",&n_teams);

	int n_matches; 
	printf("Enter the number of matches: ");
	scanf("%d",&n_matches);

	int results[n_matches][2];

	// Hash table that will store the no. of losses of each team
	int losses[n_teams+1];
	for(int i=1;i<=n_teams;i++) losses[i] = 0;  


	printf("Enter the results of each match: \n");
	for(int i=0;i<n_matches;i++) {
		scanf("%d %d",&results[i][0],&results[i][1]);

		losses[results[i][1]]+=1; // Incrementing no. of losses for the corresponding losing team
	}

	int reqd_teams[2][n_teams]; // 2D array to store required result
	// First row -> teams with no losses 
	// Second row -> teams with exacty one loss 

	int i0=0, i1=0; // Indices for each row of the array

	// Iterating through the hash table and finding the required teams
	for(int i=1;i<=n_teams;i++){
		if(losses[i]==0) reqd_teams[0][i0++] = i;
		else if(losses[i]==1) reqd_teams[1][i1++] = i;
	}

	// Finally, displaying the result
	printf("Teams with no losses: ");
	for(int i=0;i<i0;i++) printf("%d ",reqd_teams[0][i]);
	printf("\n");

	printf("Teams with exactly one loss: ");
	for(int i=0;i<i1;i++) printf("%d ",reqd_teams[1][i]);
	printf("\n");

	return 0;
}