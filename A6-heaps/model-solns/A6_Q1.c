/*
Model solution for Lab-6 Que. 1
*/
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function for creating max-heap at node i
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // finding the largest among the given node and its childrens.
    if (left < N && arr[left] > arr[i])
    {
        largest = left;
    }
    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
    }

    // if ith node is largest, that means it is already max heap.
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        // recursively call heapify bcoz swapping may have affected the remaining tree.
        heapify(arr, N, largest);
    }
    return;
}

int selectSweets(int arr[], int N, int k)
{
    int sum = 0;

    //  picking sweets k times
    for (int i = 0; i < k; i++)
    {
        // take out half sweets from the root element of max-heap.
        arr[0] = arr[0] - arr[0] / 2;

        // again heapify bcoz the above operation may have disturbed the max heap property.
        heapify(arr, N, 0);
    }

    // finding sum of the remaining sweets
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int answer;

    ////////// Taking Inputs: /////////////
    printf("Enter the number of containers = ");
    int N, k;
    scanf("%d", &N);
    int arr[N];

    printf("Container = ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k = ");
    scanf("%d", &k);

    // creating max heap from container values.
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
    answer = selectSweets(arr, N, k);
    printf("Remaining total sweets: %d", answer);
    return 0;
}
