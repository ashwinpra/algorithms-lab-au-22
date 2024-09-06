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

	/* Improved solution -> O(m*n)
	Check the first row and first column, find the affected rows and columns (if any), 
	and skip these rows and columns while checking the rest.
	Keep going like this by skipping the affected rows and columns, and finally separately change these
	row and column values to 0

	*/

	int rows[m],columns[n];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(fruit[i][j]==0) {
				rows[i]=0;
				columns[i]=0;
			}
		}
	}

	printf("After removing affected fruits: \n");
	printArr(fruit);

	return 0;
}