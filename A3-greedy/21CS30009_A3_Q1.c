/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdio.h>
#include<string.h>

// Utility functions to find minimum and maximum out of 2 numbers, respectively 
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)

/* Asproach:
	For each dracula, we will get the lower and upper bounds within which it can capture
	Within these lower and upper bounds, we will greedily choose the person whose index in the sequence is lowest
	Like this, we can ensure that every dracula gets one victim if it is possible within the restrictions
*/ 

// structure to store lower and upper range of capture of a dracula
typedef struct{
	int lower; 
	int higher;
}range;

// Greedy algorithm that returns the maximum no. of people that can be captured
int solveGreedy(char* seq, int n_dracula, range* ranges){

	int capture_count =0; // will keep track of the no. of captures 
	int drac_count=0; // will keep track of how many draculas we have checked for 

	for(int i=0;seq[i]!='\0';i++){
		if(seq[i]=='1'){
			for(int j=ranges[drac_count].lower;j<=ranges[drac_count].higher;j++){
				if(seq[j]=='0'){
					// It is a person who can be captured. 
					// So we capture him, change index to 2 (to denote that person has been captured), and increase capture count
					seq[i]='2';
					capture_count++;
					// Since the dracula already captured a person, it cannot capture anymore, so we break
					break;
				}
			}
			drac_count++;
		}
		if (drac_count>=n_dracula) break; // Break if we are done checking for every dracula
	}
	// Final capture count is returned 
	return capture_count;
}


int main()
{	
	// Taking the binary sequence and distance d as input 

	char bin_seq[100];
	printf("Note: Enter the data without spaces\n");
	printf("Enter the binary sequence of people and dracula: ");
	scanf("%s", bin_seq);

	int d;
	printf("Enter the distance d: ");
	scanf("%d",&d);

	
	// Converting the binary sequence that was taken as a string, into an integer array
	// Also finding the number of draculas 
	int n_dracula=0;

	for(int i=0;bin_seq[i]!='\0';i++)
		if(bin_seq[i]=='1') n_dracula++;

	int n = strlen(bin_seq);

	range ranges[n_dracula]; // Array to store lower and upper range for each dracula 
	int j=0; // To change index of the "ranges" array 
	for(int i=0;i<bin_seq[i]!='\0';i++){ 
		if(bin_seq[i]=='1'){
			// it is a dracula, so we find its range 
			// while checking range, we must also make sure that it doesnt go out of bounds
			ranges[j].lower = max(i-d,0);
			ranges[j].higher = min(i+d,n-1);
			j++;
		}
		if(j>=n_dracula) break; // Break if we have found range for all draculas 
	}

	// getting the answer from greedy algorithm
	int ans =  solveGreedy(bin_seq,n_dracula, ranges);

	printf("Total number of captures = %d\n", ans);

	return 0;	
}