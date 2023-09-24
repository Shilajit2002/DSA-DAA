#include <stdio.h>

int max, min, arr[100000];

void maxmin(int low, int high)
{
    int max1, min1, mid;

    // For 1 Element
    if (low == high)
    {
        max = min = arr[low];
    }

    // For 2 Elements
    else if (low == high - 1)
    {
        if (arr[low] > arr[high])
        {
            max = arr[low];
            min = arr[high];
        }
        else
        {
            max = arr[high];
            min = arr[low];
        }
    }

    // More than 2 Elements
    else
    {
        mid = (low + high) / 2;
        maxmin(low, mid);
        max1 = max, min1 = min;
        maxmin(mid + 1, high);
        if (max < max1)
        {
            max = max1;
        }
        if (min > min1)
        {
            min = min1;
        }
    }
}

int main()
{
    int n, i, low, high;
    printf("Enter the no. of Elements = ");
    scanf("%d", &n);
    printf("Enter the %d Elements = ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    low = 0, high = n - 1, max = min = arr[0];
    maxmin(low, high);

    printf("Maximum Element is =  %d\n", max);
    printf("Minimum Element is =  %d", min);
}