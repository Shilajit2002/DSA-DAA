#include <stdio.h>

int MergeArr(int n3, int n2, int n1, int *arr1, int *arr2)
{
    int mergearr[n3];

    for (int i = 0; i < n1; i++)
    {
        mergearr[i] = arr1[i];
    }

    for (int i = 0; i < n2; i++, n1++)
    {
        mergearr[n1] = arr2[i];
    }

    printf("\n\t** Merged Array **\n\n");
    for (int i = 0; i < n3; i++)
    {
        printf("| %d |", mergearr[i]);
    }
}

int main()
{
    int n1, n2, n3;
    printf("Enter the total no. of element of 1st Sorted Array = ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter the 1st Sorted array Elements = ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the total no. of element of 2nd Sorted Array = ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter the 1st Sorted array Elements = ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    n3 = n1 + n2;

    MergeArr(n3, n2, n1, arr1, arr2);
}