

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int solve(int web1[],int web2[],int n,int dp[])
{
	if(n<0)
	  return 0;
	if(n==0)
	  return web1[0]>web2[0]?web1[0]:web2[0];
	if(dp[n]!=-1)
	  return dp[n];
	// taking the data of second website of current day so now we can not consider data of previous day(that's why n becomes n-2)
	int ans1 = web2[n] + solve(web1,web2,n-2,dp);
	
	// taking the data of first website hence we can also consider data of previous day(that's why n becomes n-1)
	int ans2 = web1[n] + solve(web1,web2,n-1,dp);
	
	// finally we take the maximum of (ans1,ans2)
	if(ans1>ans2)
	  return dp[n]=ans1;
	
	return dp[n] = ans2;
}

int main()
{
	int days,i;
	printf("Enter the no of days\n");
	scanf("%d",&days);
	int website_1[days];
	int website_2[days];
	printf("enter the data for the first website\n");
	
	for(i=0;i<days;i++)
	{
	   scanf("%d",&website_1[i]);
	}
	
	printf("enter the data for the second website\n");
	for(i=0;i<days;i++)
	{
	   scanf("%d",&website_2[i]);
	}
	
	int dp[days];
	memset(dp,-1,sizeof(dp));
	int ans = solve(website_1,website_2,days-1,dp);
	printf("maximum data u can utilize are %dGB\n",ans);
	
	return 0;
}
