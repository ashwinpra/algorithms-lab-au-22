#include <stdio.h>

const int INF = 1e9;

int min(int a, int b) {
	if (a<b) return a;
	else return b;
}

int max(int a, int b) {
	if (a>b) return a;
	else return b;
}

int getSum(int l, int r, int *w) {
	int i, res=0;
	for (i=l;i<=r;i++){
		res+=w[i];
	}
	return res;
}

// rec(c, k, n, w) will return max possible leftover (min) over all possible k splits
// for the sub array w[c...n-1]
int rec(int c, int k, int n, int *w) {
	if (n-c<k+1)
		return -INF;

	if (k==0)
		return getSum(c,n-1,w);

	int i, res=0;

	for (i = c + 1; i < n; i++) {
		int currMin = min(getSum(c,i-1,w), rec(i,k-1,n,w));
		res = max(res, currMin);
	}
	return res;
}

int main()
{
	int k,n;
	printf("Enter the number of friends: ");
	scanf("%d",&k);
	printf("Enter the number of chicken pieces: ");
	scanf("%d",&n);

	int arr[n];
	printf("Enter the consecutive weights (in grams) of the pieces:\n");
	for (int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("Maximum weight of chicken piece(s) that you will get is: %d grams", rec(0,k,n,arr));
	return 0;
}