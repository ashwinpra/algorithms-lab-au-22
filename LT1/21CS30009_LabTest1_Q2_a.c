/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>

/*
	Approach: 
		- Since the points of each assignment is the same, the only weightage given is to the 
		  number of hours taken.
		- So we simply greedily choose the assignment which takes lowest time at each step, until 
		  we are out of time.  
*/

// Merge sort to sort the array of hours taken
void mergeSort(int* a, int p, int r){
	if(p==r) return;
	if(p<r){
		int q = (p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);

		int n1 = q-p+1; 
		int n2 = r-q;
		int L[n1], R[n2];

		for(int i=0;i<n1;i++) L[i] = a[p+i];
		for(int i=0;i<n2;i++) R[i] = a[q+1+i];

		int l_index = 0, r_index = 0, a_index = p;
		
		while(l_index < n1 && r_index < n2){
			if(L[l_index]<R[r_index]) a[a_index++] = L[l_index++];
			else a[a_index++] = R[r_index++];
		}

		while(l_index<n1) a[a_index++] = L[l_index++];
		while(r_index<n2) a[a_index++] = R[r_index++];
	}
}


int solveGreedy(int* hrs, int n, int M){
	// first, sort the array 
	mergeSort(hrs,0,n-1);

	int total_hrs = 0; // to keep track of total no. of hours

	// Now, greedily choose the assignments (lower hours given more priority as it is sorted accordingly)
	for(int i=0;i<n;i++){
		if(M-hrs[i]>=0){
			/* This means that the corresponding assignment can be done, so the following actions are taken: 
				Add the hrs taken for this assignment to the total hrs
				Subtract this from the hrs left 
			*/
			total_hrs+=hrs[i];
			M-=hrs[i];
		}
		// Terminating if there are no more hours left
		if(M<=0) break;
	}
	// Returning the final total hours
	return total_hrs;

}

int main()
{	
	// Taking no. of assignments, total hours left and time taken for each assignment as input from user

	int n;
	printf("Enter the number of assignments (n): ");
	scanf("%d",&n);

	int M;
	printf("Enter the total number of hours left (M): ");
	scanf("%d",&M);

	int hrs[n];
	printf("Enter the number of hours needed to solve each assignment: ");
	for(int i=0;i<n;i++) scanf("%d",&hrs[i]);

	// Solving greedily to get minimum effort 
	int min_hrs = solveGreedy(hrs,n,M);

	printf("Minimum effort needed (by greedy strategy) = %d\n",min_hrs);

	return 0;
}