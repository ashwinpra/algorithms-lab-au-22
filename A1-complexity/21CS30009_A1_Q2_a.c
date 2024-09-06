/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>

int m,n; // Globally defining dimensions of matrix

void printArr(int a[][n]){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	// Taking dimensions of matrix and its values as input
	printf("Enter dimensions of fruit matrix: ");
	scanf("%d %d",&m,&n);

	int fruit[m][n];
	printf("Enter values: ");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&fruit[i][j]);
		}
	}
	printf("Original fruit matrix: \n");
	printArr(fruit);
	/* Naive solution -> O(m*n*(m+n))
		Traverse through every element, once 0 is found, replace that and every element 
		in its row and column with some arbitrary value other than 0 and 1 (here, 2), 
		then traverse again and replace this value with 0 */

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(fruit[i][j]==0){
				for(int k=0;k<n;k++) fruit[i][k] = 2;
				for(int l=0;l<m;l++) fruit[l][j] = 2;
			}
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(fruit[i][j]==2) fruit[i][j] = 0 ;
		}
	}
	printf("After removing affected fruits: \n");
	printArr(fruit);

	return 0;
}