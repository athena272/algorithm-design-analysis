#include <stdio.h>

int binarySearch(int arr[], int n, int x)
{
    int left = 0;      // the left end of the search interval
    int right = n - 1; // the right end of the search interval
    while (left <= right)
    {                                        // continue searching while there is an interval to search
        int mid = left + (right - left) / 2; // the middle index of the interval
        if (arr[mid] == x)
        {               // if the middle element is the value we're searching for
            return mid; // return its index
        }
        if (arr[mid] < x)
        {                   // if the middle element is less than the value we're searching for
            left = mid + 1; // discard the left half of the interval
        }
        else
        {                    // if the middle element is greater than the value we're searching for
            right = mid - 1; // discard the right half of the interval
        }
    }
    return -1; // if the value is not found, return -1
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int result = binarySearch(arr, n, x);
    if (result == -1)
    {
        printf("Element is not present in the array\n");
    }
    else
    {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}
