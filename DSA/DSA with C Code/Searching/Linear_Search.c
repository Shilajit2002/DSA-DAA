#include <stdio.h>

void linear_search(int *arr, int n)
{
	int key, i;
	printf("Enter the Searching Element : ");
	scanf("%d", &key);
	for (i = 0; i < n; i++)
	{
		if (arr[i] == key)
		{
			printf("** %d found in %d position **", key, i + 1);
			break;
		}
	}

	if (i == n)
	{
		printf("** Element Not Found **");
	}
}

int main()
{
	int i, n;
	printf("Enter the total no. of Elements : ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the %d Elements : ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	linear_search(arr, n);
}