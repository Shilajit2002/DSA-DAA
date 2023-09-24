#include <stdio.h>

void binary_search(int arr[], int n)
{
	int low, high, mid, key;

	printf("Enter the Searching Element : ");
	scanf("%d", &key);

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == key)
		{
			printf("** %d Found in %d Position **", key, mid + 1);
			break;
		}
		else if (key < arr[mid])
		{
			high = mid - 1;
			// low = mid + 1;
		}
		else
			low = mid + 1;
			// high = mid - 1;
	}

	if (low > high)
	{
		printf("** Element Not Found **");
	}
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
	binary_search(arr, n);
}