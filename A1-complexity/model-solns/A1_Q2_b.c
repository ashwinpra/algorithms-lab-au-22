/*
Following is a model solutuon for Assignment - 1, Question 2(b).
Kindly note this may not be the only solution, there could be other ways of solving the same problem.
For any discrepency regarding Question 2, mail at : owais.iqbal@kgpian.iitkgp.ac.in
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, m, n, flagr=0, flagc=0;
    printf("Enter value of row:");
    scanf("%d",&m);
    printf("Enter value of column:");
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

    //Find all 0's in first column and change it to -1 (also update the flagr to 1 for if any 0's found)
    for (i=0;i<m;i++)
    {
        if(a[i][0]==0)
        {
            a[i][0]=-1;
            flagr=1;
        }
    }
    //Find all 0's in first row and change it to -1 (also update the flagc to 1 for if any 0's found)
    for (j=0;j<n;j++)
    {
        if(a[0][j]==0)
        {
            a[0][j]=-1;
            flagc=1;
        }
    }


    /*
    Array after above operations
    1 1 -1 1 1 
    1 1 1 1 1 
    1 1 1 0 1 
    1 1 1 1 1 
    -1 1 1 1 1    
    */  


    //This loop runs through the sub-matrix barring 1st row and 1st column 
    //Here we just to set the row and column headers(1st row and column) to 0, where ever we find 0 in sub matrix
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(a[i][j]==0)
            {
                a[i][0]=0;
                a[0][j]=0;
            }
        }
    }
    /*
    Array after above operations
    1 1 -1 0 1 
    1 1 1 1 1 
    0 1 1 0 1 
    1 1 1 1 1 
    -1 1 1 1 1 
      */  
    
    
    //Traverse the sub-matrix, and for any element if the corresponding value in 1st row or 1st column is 0 or -1 then change the current element to 0
    for (i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(a[i][0]==0 || a[i][0]==-1 || a[0][j]==0 || a[0][j]==-1)
            {
                a[i][j]=0;
            }
        }
    }
    /*
    Array after above operations
    1 1 -1 0 1 
    1 1 0 0 1 
    0 0 0 0 0 
    1 1 0 0 1 
    -1 0 0 0 0 
    */


    //if flagr == 0, then change the whole 1st row to 0
    if(flagr==1)
    {
        for (i=0;i<m;i++)
            a[i][0]=0;
    }
    //if flagc == 0, then change the whole 1st column to 0
    if(flagc==1)
    {
        for (j=0;j<n;j++)
            a[0][j]=0;
    }
    
    //Print the whole matrix
    printf("\nOutput is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);      
        printf("\n");
    }
    
    /*
    Array after above operations 
    0 0 0 0 0 
    0 1 0 0 1 
    0 0 0 0 0 
    0 1 0 0 1 
    0 0 0 0 0
    */
}

