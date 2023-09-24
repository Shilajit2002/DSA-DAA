#include <stdio.h>

void Print(int *arr, int n)
{
    printf("Descending Order Sorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Merge(int *arr, int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int b[10000];

    while (i <= mid && j <= ub)
    {
        if (arr[i] >= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }

    for (k = 0; k <= ub; k++)
    {
        arr[k] = b[k];
    }
}

void Merge_Sort(int *arr, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        Merge_Sort(arr, lb, mid);
        Merge_Sort(arr, mid + 1, ub);
        Merge(arr, lb, mid, ub);
    }
}

int main()
{
    int n, lb, ub;

    printf("Enter total no. of Elements = ");
    scanf("%d", &n);

    int arr[n], i;

    printf("Enter %d Element = ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    lb = 0;
    ub = n - 1;

    Merge_Sort(arr, lb, ub);
    Print(arr, n);
}