#include <stdio.h>

void Print(int *arr, int n)
{
    printf("Ascending Order Sorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Insertion_Sort(int *arr, int n)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
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

    Insertion_Sort(arr, n);
    Print(arr, n);
}