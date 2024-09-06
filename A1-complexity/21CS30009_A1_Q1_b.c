/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdio.h>
#include<math.h>

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


	/* Improved solution -> O(N): 
		Divide it into sqrt(N) subarrays 
		Find max and min element in each subarray 
		Traverse through every max and every min to find a suitable pair 
	*/

	int srt = sqrt(n);

	int maxs[srt],mins[srt]; 
	// arrays to store max and min value indices respectively, of each subarray

	// O(sqrt(N)*sqrt(N)) => O(N)
	for(int i=0;i<n;i+=srt){
		// Giving an initial value to the max and min (which may or may not change)
		maxs[i/srt] = i;
		mins[i/srt] = i;
		for(int j=0;j<srt;j++){
			if(pop[i+j]>pop[maxs[i/srt]]) maxs[i/srt] = i+j;

			if(pop[i+j]<pop[mins[i/srt]]) mins[i/srt] = i+j;
		}
	}

	int max_diff = -10000;
	// Now traverse through both arrays and find matching pair -> O(sqrt(N)*sqrt(N)) => O(N)
	for(int i=0;i<srt;i++){
		for(int j=0;j<srt;j++){
			if(pop[maxs[i]]>pop[mins[j]] && maxs[i]-mins[j] > max_diff) {
				max_diff = maxs[i]-mins[j];
		}
	}
}	
	
	max_diff == -10000 ? printf("None\n") : printf("Maximum number of hops required: %d\n",max_diff);

	return 0; 	
}