/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdio.h>
#include<string.h>

// Utility function to compute the maximum of two numbers
#define max(a,b) (a>b?a:b)

/*
	Approach: 

	- First get the LCS (longest common subsequence) using dynamic programming
	- Then we note that the SCS essentially contains all the elements of X and Y, barring the duplicates that are part of LCS
	- So SCS is constructed as (X-LCS)+(Y-LCS)+(LCS)
*/


// DP method to get the LCS
void LCS(char*x, char*y, int m, int n, int s[m+1][n+1]){

	// base case: if i or j = 0, s[i][j]=0
	s[0][0]=0;
	for(int i=1;i<=m;i++) s[i][0]=0;
	for(int j=1;j<=n;j++) s[0][j]=0;

	// filling the DP array "s" iteratively
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){
				s[i][j] = s[i-1][j-1]+1;
			} 
			else{ 
				s[i][j] = max(s[i-1][j],s[i][j-1]);
			}
		}
	}

}
// Obtaining the actual LCS from the DP array
// Also, keeping track of the index in x and y, of the characters that are part of LCS
void getLCS(char*x, char*y, int m, int n, int s[m+1][n+1], char* LCS_str, int* x_idc, int *y_idc){
	// Variables to keep track of indices of x, y and LCS string 
	// size of LCS is s[m][n]
	// in this way, we are obtaining LCS in reverse order, so we start indices from the end in order to store it in reverse
	// order as well (so that finally it is in right order)
	int i = m, j = n, k = s[m][n]; 

	LCS_str[k--] = '\0'; // last character = null character, so that it is a string

	while(i>0 || j>0){
		if(x[i-1]==y[j-1]){
			LCS_str[k] = x[i-1];
			x_idc[i-1]=0;
			y_idc[j-1]=0; 
			i--;
			j--;
			k--;
		}
		else{
			if(s[i-1][j]>=s[i][j-1]) i--;
			else j--;
		}
	}
}

/*
	To get the SCS, now that we have the LCS
	SCS = (X, except overlapping characters wth LCS) + (Y, except overlapping characters with LCS) + (LCS)
	First copy all characters from X except those that appear in LCS 
	Do the same with Y
	Finally copy the LCS into the SCS
*/
void getSCS(char* x, char*y, int m, int n, int l_lcs, char* LCS_str, int* x_idc, int* y_idc, char* SCS_str){


	int scs_idx = 0;

	// Copy from x 
	for(int i=0;i<m;i++){
		// copy if it not is in LCS
		if(x_idc[i]==1) SCS_str[scs_idx++] = x[i]; 
	}

	// Copy from y
	for(int i=0;i<n;i++){
		// copy if it not is in LCS
		if(y_idc[i]==1) SCS_str[scs_idx++] = y[i]; 
	}

	// Now copy from LCS
	for(int i=0;i<l_lcs;i++) SCS_str[scs_idx++] = LCS_str[i];

	// Finally, append a null character to make it a string 
	SCS_str[scs_idx] = '\0';
}

int main()
{
	// Taking user input for the two strings
	char x[100], y[100];

	printf("Enter the first string: ");
	scanf("%s",x);
	printf("Enter the second string: ");
	scanf("%s",y);

	int m = strlen(x);
	int n = strlen(y);

	// Declaring DP array, and filling it through the function
	int s[m+1][n+1];

	LCS(x,y,m,n,s);

	// Length of lcs = s[m][n]
	int l_lcs = s[m][n];

	// Length of SCS = (length of x-length of LCS) + (length of y-length of LCS) + length of LCS
	// 			     = length of x + length of y - length of LCS 
	int l_scs = m+n-l_lcs;

	printf("The SCS length is %d\n",l_scs);

	// Along with getting LCS, I am also storing the indices at which these characters appearead in X and Y, so that 
	// they can be skipped while constructing SCS
	char LCS_str[l_lcs+1];
	int x_indices[m], y_indices[n];
	// pre fill both with 1 
	for(int i=0;i<m;i++) x_indices[i]=1;
	for(int i=0;i<n;i++) y_indices[i]=1;

	// Calling function to get LCS string and indices arrays
	getLCS(x,y,m,n,s,LCS_str, x_indices, y_indices);

	char SCS_str[l_scs];
	// Calling function to get the final SCS string, and then displaying it
	getSCS(x,y,m,n,l_lcs,LCS_str,x_indices, y_indices, SCS_str);

	printf("SCS string is: %s\n", SCS_str);

	return 0;
}