// C program to find odd occcuring elements in an array

#include <stdio.h>

// Function to return the only odd
// occurring element
int findOdd(int arr[], int n)
{
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}

int main(void)
{
    int arr[] = { 12, 12, 14, 90, 90, 90, 14, 14, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The odd occurring element is %d\n",
           findOdd(arr, n));
    return 0;
}
