

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
   int tmp = *x;
   *x = *y;
   *y = tmp;
}

void min_heapify(int i,int merged_arr[],int N)   // function to heapify
{
   int l_child= 2*i+1;
   int r_child= 2*i+2;
   int par_idx=i;
   if(l_child<N && merged_arr[par_idx]>merged_arr[l_child])
      par_idx=l_child;
   if(r_child<N && merged_arr[par_idx]>merged_arr[r_child])
      par_idx=r_child;
   
   if(par_idx != i)
   {
     
     swap(&merged_arr[par_idx],&merged_arr[i]);
     min_heapify(par_idx,merged_arr,N);
   }
   
}

void min_heap(int merged_arr[],int N)   // function to build min heap
{
   int i;
   for(i=(N/2)-1;i>=0;i--)
   {
      min_heapify(i,merged_arr,N);
   }
  
}

int main()
{
    
    int n,m,i;
    printf("enter the value of m and n\n");
    scanf("%d%d",&m,&n);
    int arr1[m];
    int arr2[n];
    for(i=0;i<m;i++)
    {
       scanf("%d",&arr1[i]);
    }
    for(i=0;i<n;i++)
    {
       scanf("%d",&arr2[i]);
    }
    
    int k=10;
    
    int N = n*m;
    
    int merged_arr[N];
    int j=0,l=0;
    for(i=0;i<m;i++)
    {
       for(j=0;j<n;j++)
       {
          merged_arr[l]= arr1[i] + arr2[j];  // calculating the all possible sum
          l++;
       }
    }
    
    min_heap(merged_arr,N);    // BUilding the min heap of index sum
    printf("k min index sum are as follows:\n");
    for(i=0;i<k;i++)
    {
      printf("%d ",merged_arr[0]);
      swap(&merged_arr[0],&merged_arr[N-i-1]);
      min_heapify(0,merged_arr,N-i-1);
    }
    printf("\n");
    return 0;
}
