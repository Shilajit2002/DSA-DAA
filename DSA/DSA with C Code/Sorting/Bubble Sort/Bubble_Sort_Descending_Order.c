#include <stdio.h>

void Print(int *arr, int n)
{
    printf("Descending Order Sorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Bubble_Sort(int *arr, int n)
{
    int i, j, temp, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = 1;
            }
        }

        // Condition for Array is already sorted
        if (flag == 0)
        {
            break;
        }
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

    Bubble_Sort(arr, n);
    Print(arr, n);
}