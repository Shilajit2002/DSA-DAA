#include <stdio.h>

void Print(int *arr, int n)
{
    printf("Descending Order Sorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int Partition(int *arr, int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb, end = ub;

    while (start < end)
    {
        while (arr[start] >= pivot)
        {
            start++;
        }
        while (arr[end] < pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp;
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    int temp;
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

void Quick_Sort(int *arr, int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = Partition(arr, lb, ub);
        Quick_Sort(arr, lb, loc - 1);
        Quick_Sort(arr, loc + 1, ub);
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

    Quick_Sort(arr, lb, ub);
    Print(arr, n);
}