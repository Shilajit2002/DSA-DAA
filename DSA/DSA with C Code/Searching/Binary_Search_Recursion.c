#include <stdio.h>

int binary_search(int arr[], int l, int r, int key)
{
    if (r >= l)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            return binary_search(arr, l, mid - 1, key);
        }
        return binary_search(arr, mid + 1, r, key);
    }
    return -1;
}

int main()
{
    int n, i;
    printf("Enter the total no. Elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the %d Elements in Sorted Order : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the Searching Element : ");
    scanf("%d", &key);

    int result = binary_search(arr, 0, n - 1, key);
    (result == -1) ? printf("%d is not present in array", key) : printf("%d is present at %d position", key, result + 1);
}