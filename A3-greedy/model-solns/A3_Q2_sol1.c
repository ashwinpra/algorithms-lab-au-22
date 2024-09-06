# include<stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int findIndex(int A[], int size, int value)
{
    int i;
    for (i=0; i < size; i++)
    {
        if (A[i] == value)
            return i;
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if(A[i] == 0)
            continue;
        else
            printf("%d ", A[i]);
    }
        
    printf("\n");
}

int main()
{
    int n, i, j, tmp, index, maxtime;
    int sum=0;
    printf("Enter the number of sweet varieties: \n");
    scanf("%d", &n);
    int SweetArr[n];
    int CostArr[n];
    int TempArr[n];
    int OutArr[n];

    for (i=0; i < n; i++)
    {
        OutArr[i]=0;
    }

    printf("Enter the latest time to deliver each item: \n");

    for(i=0; i < n; i++)
    {
        scanf("%d", &tmp);
        SweetArr[i] = tmp;
    }

    printf("Enter the cost (in Rupees) of preparing each item: \n");

    for(i=0; i < n; i++)
    {
        scanf("%d", &tmp);
        CostArr[i] = tmp;
        TempArr[i] = tmp;
    }

    mergeSort(TempArr, 0, n-1);
 
    // printf("\nSorted array is \n");
    // printArray(TempArr, n);

    for (i=0; i < n; i++)
    {
        index = findIndex(CostArr, n, TempArr[i]);
        maxtime = SweetArr[index];
        

        for(j=maxtime; j>=1; j--)
        {
            if(OutArr[j] == 0)
            {
                OutArr[j] = index+1;
                sum += CostArr[index];
                break;
            }

        }
        
    }
    
    printf("\nThe optimal choice of sweet ietms are: ");
    printArray(OutArr, n);
    
    printf("The total cost of preparing the items: %d", sum);

    return 0;


}