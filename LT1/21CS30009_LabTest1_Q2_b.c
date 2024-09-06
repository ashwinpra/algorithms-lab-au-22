/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)

const int INF  = 1e9; // Defining a large number to be infinity

/*
	Approach:
		- DP approach is adopted, now that points are also to be considered.
		- A DP table is created with the logic given in question
		- From it, the required answers are obtained (explained in subsequent comments) 
*/
	
void solveDP(int *pts, int* hrs, int n, int M, int P, int T[n+1][P+1]){

	// T[i][p] -> minimum effort to get *exactly* p points, by attempting assignments from 1 to i
	// if *exactly* p points cannot be achieved, it is stored as infinity

	// pre-filling T with infinity first
	for(int i=0;i<n+1;i++){
		for(int j=0;j<P+1;j++){
			T[i][j] = INF;
		}
	}

	// Corner case: T[i][0] = 0 for all i within the range of array
	for(int i=0;i<n+1;i++) T[i][0]=0;

	// Now filling the DP matrix
	for(int i=1;i<=n;i++){
		for(int p=1;p<=P;p++){
			// 2 cases -> solving or not solving i-th assignment

			// If p < pts[i], we cannot solve the assignment, so T[i][p] = T[i-1][p]
			if(p<pts[i]) {
				T[i][p] = T[i-1][p];
			}

			// If p >= pts[i], we have 2 options: either solve or don't solve, choose the option which has lesser effort (but also check whether they exceed the total hrs or not)
			else{
				// if solving 
				int m_s = hrs[i]+T[i-1][p-pts[i]];
				// if not solving 
				int m_ns = T[i-1][p];

				// if m_s is greater than M, it is not valid, so we go for m_ns directly
				// Otherwise, choose the minimum 
				T[i][p] = m_s>M ? m_ns : min(m_s,m_ns);

			}
		}
	}
}

void getAnswers(int n, int P, int T[n+1][P+1], int* max_pts, int* min_hrs){
	// now, maximum points is the maximum p such that T[n][p]!=INF
	// minimum hours to achieve is T[n][p]
	int maxp=0;
	for(int p=1;p<=P;p++){
		if(T[n][p]!=INF){
			maxp=max(maxp,p);
		}
	}
	// Assigning the obtained max points to the pointer, and from it, min hours is also obtained, as T[n][maxp]
	*max_pts = maxp;
	*min_hrs = T[n][maxp];
}

int main()
{
	// Taking no. of assignments, total hours left, points time taken for each assignment as input from user

	int n;
	printf("Enter the number of assignments (n): ");
	scanf("%d",&n);

	int M;
	printf("Enter the total number of hours left (M): ");
	scanf("%d",&M);

	// Both points and hours arrays are made 1-indexed for convenience

	int pts[n+1];
	printf("Enter the points of each assignment: ");
	for(int i=1;i<=n;i++) scanf("%d",&pts[i]);

	// getting P -> total sum of all points
	int P=0;
	for(int i=1;i<=n;i++) P+=pts[i];

	int hrs[n+1];
	printf("Enter the number of hours needed to solve each assignment: ");
	for(int i=1;i<=n;i++) scanf("%d",&hrs[i]);

	int T[n+1][P+1]; /// DP matrix
	int max_pts, min_hrs; // To store maximum points and minimum hrs (effort) [Both obtained from function]

	// Function to fill DP matrix
	solveDP(pts,hrs,n,M,P,T);

	// Function to get required answers based on DP matrix
	getAnswers(n,P,T,&max_pts,&min_hrs);

	printf("Maximum points = %d\n",max_pts);
	printf("Minimum effort = %d\n", min_hrs);

	return 0;
}