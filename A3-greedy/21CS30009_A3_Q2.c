/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include <stdio.h>

/*
	Approach: 
	- First of all, in order to minimise the costs, we will greedily choose the sweets in 
	  order of their price, from lowest to highest -> i.e. we sort the sweets in order of cost
	- For each sweet that we check, we try to allot it to the slot that is closest to its latest time.
	  For example, if the latest time is 9PM, we try to prepare it between 8 to 9 
	- We keep looking for an open slot such that the slot we assign it is closest to the latest time.
	- If no such slot is available, we skip this sweet.

	- This way, we make sure that each sweet gets the optimal slot, so we can maximise the number of sweets 
	- Moreover, since we are checking from lowest price to highest, we are minimizing cost as well
*/

// Structure that stores the sweet variety no. (index+1), latest time to deliver and cost
typedef struct{
	int index; 
	int latest_time; 
	int cost;
}sweet;

// Merge sort to sort the array of sweets
void mergeSort(sweet* a, int p, int r){
	if(p==r) return;
	if(p<r){
		int q = (p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);

		int n1 = q-p+1; 
		int n2 = r-q;
		sweet L[n1], R[n2];

		for(int i=0;i<n1;i++) L[i] = a[p+i];
		for(int i=0;i<n2;i++) R[i] = a[q+1+i];

		int l_index = 0, r_index = 0, a_index = p;
		
		while(l_index < n1 && r_index < n2){
			if(L[l_index].cost<R[r_index].cost) a[a_index++] = L[l_index++];
			else a[a_index++] = R[r_index++];
		}

		while(l_index<n1) a[a_index++] = L[l_index++];
		while(r_index<n2) a[a_index++] = R[r_index++];
	}
}

// Greedy algorithm that will return the minimum cost and corresponding optimal choices 
int solveGreedy(sweet* sweets, int n, int* choices, int max_latest){
	// starting time = 12PM, ending time = max_latest
	// total slots = max_latest 
	int slots[max_latest]; // stores whether a slot is occupied or not -> 1 means unoccupied, 0 means occupied
	for(int i=0;i<max_latest;i++) slots[i]=1; // Filling the array with "1" i.e. unoccupied initially

	/*
		slots array will be used like this: 
		slots[0] means slot from 12PM to 1PM 
		slots[1] means slot from 1PM to 2PM 
		... and so on  =>
		slots[i] means slot from (i+12)%12 PM to [(i+12)%12 + 1] PM 
	*/ 

	int cost=0; // will keep track of the minimum cost

	int choices_index = 0; // to control the index of choices array 

	// Traversing through the sorted sweets array
	for (int i=0;i<n;i++)
	{
		// Traversing through the slots array to see if it can be accommodated in a slot
		// We will traverse in reverse order as it needs to be assigned the latest time possible

		for(int j=(sweets[i].latest_time+11)%12;j>=0;j--){
			// Bounds of the loop -> ((latest_time-1)+12)%12 to 0 -> possible slots in the array  
			if(slots[j]==1){
				/* We found the optimal slot, now we do the following: 
				 Change 1 to 0 to denote that it is occupied now 
				 Increase cost accordingly 
				 Add corresponding sweet no. to the choices array
				 Break from the loop
				 */
				slots[j]=0;
				cost+=sweets[i].cost;
				choices[choices_index++]=sweets[i].index+1;
				break;
			}
		}
	}
	// Final cost is returned
	return cost;
}

int main()
{
	// Taking all necessary inputs from user 

	int n_varieties;
	printf("Enter the number of sweet varieties: ");
	scanf("%d", &n_varieties);

	sweet sweets[n_varieties]; // array of structures to store info of every sweet

	printf("Enter the latest time to deliver each item: ");

	int max_latest = -1; // To store the maximum latest time

	for(int i=0;i<n_varieties;i++) {
		scanf("%d", &sweets[i].latest_time);
		if(sweets[i].latest_time>max_latest) max_latest = sweets[i].latest_time;
	}

	printf("Enter the cost (in Rupees) of preparing each item: ");
	for(int i=0;i<n_varieties;i++) scanf("%d", &sweets[i].cost);

	for(int i=0;i<n_varieties;i++) sweets[i].index=i; // Storing the index/variety no. of each sweet

	// Sorting the array based on cost 
	mergeSort(sweets,0,n_varieties-1);

	int choices[n_varieties]; // array to store the optimal choices (max size = n_varieties)

	// Getting the minimum cost and choices from greedy algorithm
	int min_cost = solveGreedy(sweets,n_varieties, choices, max_latest);

	printf("The optimal choice of sweet items are: ");
	for(int i=0;i<n_varieties;i++){
		// Since it is possible that the number of elements we stored in choices is less than its defined size, 
		// there could be garbage values. To avoid that, this "if" condition is added
		if(choices[i]>=1 && choices[i]<=n_varieties) printf("%d ",choices[i]);
	}

	printf("\nThe total cost for preparing the items: Rs. %d\n", min_cost);

	return 0;
}