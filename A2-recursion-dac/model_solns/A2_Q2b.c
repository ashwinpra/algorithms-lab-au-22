#include<stdio.h>

int check(int mid, int k, int n,int arr[]) {
	int count=0,sum=0;
	for(int i=0;i<n;i++) {
		sum+=arr[i];
		if(sum>=mid) {
			count++;
			sum=0;
		}
		
	}
 	if (count>=(k+1)) return 1;
 	else return 0;
}

int main() {
	int k,n;
	printf("Enter the number of friends: ");
	scanf("%d",&k);
	printf("Enter the number of chicken pieces: ");
	scanf("%d",&n);
	int arr[n];
	int hi=0;
	int lo=1e9;
	printf("Enter the consecutive weights (in grams) of the pieces:\n");
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		hi+=arr[i];
		if(arr[i]<lo) lo=arr[i];
	}

	int ans=lo;
	while(lo<=hi) {
		int mid=(hi+lo)/2;
		if(check(mid,k,n,arr)==1) {
			ans=mid;
			lo=mid+1;
		}
		else {
			hi=mid-1;
		}
	}
	printf("Maximum weight of chicken piece(s) that you will get is: %d grams", ans);
	return 0;
}

/*
	Time Complexity: O(logn * check(mid, k, n, arr)) => O(nlogn)
*/