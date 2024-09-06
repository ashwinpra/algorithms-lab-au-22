/**
 *    Author: Udaya Bhaskar Cheepurupalli
 *    For any queries regarding Question 1, mail at: udayabhaskar2001@iitkgp.ac.in       
**/

#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void print(int maxHops)
{
    printf("Maximum number of hops required: ");
    if (maxHops == 0)
        printf("None\n");
    else
        printf("%d\n", maxHops);
}

int main()
{
    int n, i, j;
    scanf("%d", &n);

    int W[n];
    for (i = 0; i < n; i++)
        scanf("%d", &W[i]);

    // rightMax[i] is the max value in the sub-array W[i..n-1]
    int rightMax[n];
    for (i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            rightMax[i] = W[i];
        else
            rightMax[i] = max(rightMax[i + 1], W[i]);
    }

    /*
        Consider the range [tail, head]
        initally it is empty
    */
    int maxHops = 0, head = -1, tail = 0;
    while (tail < n)
    {
        // move the head as far as possible for the given tail
        while ((head + 1 < n) && (W[tail] < rightMax[head + 1]))
            head++;

        maxHops = max(maxHops, head - tail);

        /*
           move the tail ahead by one step, 
           continue with the same head 
           as we have already considered (head - tail) and lesser length hops 
           and we are looking for a better answer
        */
        if (tail < head)
            tail++;
        else
        {
            // make it empty if head didn't move
            tail++;
            head = tail - 1;
        }
    }

    /*
      Time Complexity: O(n)
      because the outer while loop runs for n times
      and the inner while loop runs for n times over all the outer loop iterations, 
      as head increases monotonically and initialized only once
      Note that in the inner while loop head moves in one direction and stops when reached n
    */

    print(maxHops);

    return 0;
}