#include <stdio.h>

void Print(int *arr, int n)
{
    printf("Descending Order Sorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Selection_Sort(int *arr, int n)
{
    int max, i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        max = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

int main()
{
    int n;

    printf("Enter total no. of Elements = ");
    scanf("%d", &n);

    int arr[n], i;

    printf("Enter %d Element = ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    Selection_Sort(arr, n);
    Print(arr, n);
}