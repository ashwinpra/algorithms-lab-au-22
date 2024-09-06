/* Model solution for lab 3 question 2 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    typedef struct sweet
    {
        int id;
        int deadline;
        int cost;
    } sweet;

    int compare(const void *a, const void *b)
    {
        sweet *temp1 = (sweet *)a;
        sweet *temp2 = (sweet *)b;
        return (temp1->cost - temp2->cost); // this function should return negative value so that a comes before b in the sorted list
    }

    printf("Enter the number of sweets varities: ");
    int n;
    int result[12], total_cost = 0;
    bool slot[12];
    scanf("%d", &n);

    // initially all the slots are free
    for (int i = 0; i < 12; i++)
    {
        slot[i] = false; // slot[i] = false means that slot is free.
    }

    struct sweet arr[n];


    // Taking inputs
    for (int i = 0; i < n; i++)
    {
        arr[i].id = i + 1;
    }

    printf("Enter the latest time to deliver each item: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].deadline);
    }

    printf("Enter the cost of preaparing each item: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].cost);
    }

    // sorting the structure according to their costs
    qsort(arr, n, sizeof(sweet), compare);

    for (int i = 0; i < n; i++)
    {

        // Find a free slot for this sweet (start
        // from the last possible slot)
        for (int j = arr[i].deadline - 1; j >= 0; j--)
        {

            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;                         // Add this sweet to the result
                slot[j] = true;                        // Make this slot occupied
                total_cost = total_cost + arr[i].cost; // add cost
                break;
            }
        }
    }

    printf("The optimal choice of sweet item are: ");
    for (int i = 0; i < 12; i++)
    {
        if (slot[i])
        {
            printf("%d ", arr[result[i]].id);
        }
    }
    printf("\nThe total cost of preparing the items : Rs. %d", total_cost);
    return 0;
}