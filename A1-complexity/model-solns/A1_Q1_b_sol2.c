#include <stdio.h>

#define max(i, j) (((i) > (j)) ? (i) : (j))

int maxHops(int city[], int n)
{
    int diff = -999999;

    // base case
    if (n == 0) {
        return diff;
    }
 
    // create an auxiliary array of size n
    int aux[n];
 
    // aux[j] stores the maximum element in subarray city[j, n-1]
    aux[n - 1] = city[n - 1];
    for (int j = n - 2; j >= 0; j--) {
        aux[j] = max(city[j], aux[j + 1]);
    }
 
    // Find maximum j-i using the auxiliary array
    for (int i = 0, j = 0; i < n && j < n; )
    {
        if (city[i] < aux[j])
        {
            diff = max(diff, j - i);
            j++;
        }
        else {
            i++;
        }
    }
 
    return diff;
}
 
int main()
{
    int i, n, h;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    int city[n];
    printf("\nEnter the populations: ");
    for (i=0 ; i<n ; i++){
        scanf("%d", &city[i]);
    }
    
    h = maxHops(city, n);
    
    printf("\nMaximum number of hops required: %d", h);
 
    return 0;
}
