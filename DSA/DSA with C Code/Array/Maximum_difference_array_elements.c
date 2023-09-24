#include <stdio.h>

void max_diff(int size, int arr[size])
{
    int i, j, max_difference, a, b, a_index, b_index;

    max_difference = arr[1] - arr[0];
    a = arr[1];
    b = arr[0];
    a_index = 1;
    b_index = 0;

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] - arr[i] > max_difference)
            {
                max_difference = arr[j] - arr[i];
                a = arr[j];
                b = arr[i];
                a_index = j;
                b_index = i;
            }
        }
    }
    printf("Maximum Difference is = %d", max_difference);
    printf("\n** The two numbers are **\nIndex1 [%d] = %d\nIndex2 [%d] = %d", a_index, a, b_index, b);
}

int main()
{
    int size, i = 0;
    printf("Enter total no of elements = ");
    scanf("%d", &size);
    int arr[size];
    if (size > 1)
    {
        printf("Enter %d elements = ", size);
        for (i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
        max_diff(size, arr);
    }
    else
    {
        printf("`~`Plz Enter Minimum Two Elements `~`");
    }
}