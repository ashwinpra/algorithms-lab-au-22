/*
Following is a model solutuon for Assignment - 1, Question 2(a).
Kindly note this may not be the only solution, there could be other ways of solving the same problem.
For any discrepency regarding Question 2, mail at : owais.iqbal@kgpian.iitkgp.ac.in
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, m, n, k;
    
    //Taking the input for m and n
    printf("Enter m:");
    scanf("%d",&m);
    printf("Enter n:");
    scanf("%d",&n);
    
    int a[m][n];
    
    //Taking the input for array
    printf("Enter the array:\n");
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    //Converting the 0's to -1 in array
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)
                a[i][j]=-1;


        }
    }
    
    //Changing the rows and columns to 0 wherever -1 exists
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==-1)
            {
                for(k=0;k<m;k++)
                {
                    a[k][j] = 0;
                }
                for(k=0;k<m;k++)
                {
                    a[i][k] = 0;
                }
            }
        }
    }
    
    //Printing the final array
    printf("\nOutput is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);      
        printf("\n");
    }
}


