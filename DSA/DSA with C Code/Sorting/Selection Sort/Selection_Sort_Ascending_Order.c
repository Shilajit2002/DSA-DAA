#include <stdio.h>

void Print(int *arr, int n)
{
    printf("Ascending Order Sorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Selection_Sort(int *arr, int n)
{
    int min, i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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