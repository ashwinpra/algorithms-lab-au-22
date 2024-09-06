#include<stdio.h>
#include<string.h>
int main(){
      char str1[50],str2[50],ans[100];
      scanf("%s", str1);
      scanf("%s", str2);
      int n=strlen(str1),m=strlen(str2);
      int dp[n+1][m+1];
      for(int i=0;i<=n;i++)
      {
           	for(int j=0;j<=m;j++)
            {
                	if(i==0 || j==0){
                    	dp[i][j]=0;
                	}
                	else if(str1[i-1]==str2[j-1]){
                    	dp[i][j]=1+dp[i-1][j-1];
                	}
                	else{
                        if(dp[i-1][j]>dp[i][j-1]){dp[i][j]=dp[i-1][j];}
                        else{dp[i][j]=dp[i][j-1];}
                	}
                  // printf("%d   ",dp[i][j]);
        	}
            // printf("\n");
      }
  	int i=n,j=m,k=0;
  	while(i>0 && j>0)
  	{
      	if(str1[i-1]==str2[j-1])
      	{
          		ans[k++]=str1[i-1];
                  i--;
          		j--;
      	}
      	else
      	{
          		if(dp[i-1][j]>dp[i][j-1])
          		{
                        ans[k++]=str1[i-1];
              		i--;
          		}
          		else
          		{
                        ans[k++]=str2[j-1];
              		j--;
          		}
      	}    
  	}
  	while(i>0)
  	{
            ans[k++]=str1[i-1];
      	i--;
  	}
  	while(j>0)
  	{
            ans[k++]=str2[j-1];
      	j--;
  	}
      for(i=0;i<k/2;i++){
            char a=ans[i];
            ans[i]=ans[k-i-1];
            ans[k-i-1]=a;
      }
      printf("%d \n",k);
      for(int i=0;i<k;i++){
            printf("%c",ans[i]);
      }
      printf("\n");
}