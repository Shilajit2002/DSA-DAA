#include <stdio.h>

void traversal(int arr[], int used_size)
{
	int i;

	// Scanning the Element
	printf("Enter the %d elements : ", used_size);
	for (i = 0; i < used_size; i++)
	{
		scanf("%d", &arr[i]);
	}

	// Printing the Element
	printf("The elements are : ");
	for (i = 0; i < used_size; i++)
	{
		printf("%d\t", arr[i]);
	}
}

void anotherinsertion(int arr[], int used_size, int element, int index)
{
	// Another Insertion pattern
	arr[used_size] = arr[index - 1];
	arr[index - 1] = element;

	// Print the new Element
	printf("New elements are : ");
	for (int i = 0; i <= used_size; i++)
	{
		printf("%d\t", arr[i]);
	}
}

void insertion(int arr[], int used_size)
{
	int element, index, i, k;

	// Details of Inserted Element
	printf("Enter the Element to be inserted : ");
	scanf("%d", &element);
	printf("Enter the position where the element to be inserted : ");
	scanf("%d", &index);

	printf("*** Are You See 1st Insertion Technique or 2nd Insertion Technique?..If 1st press 1 else press 2 *** : ");
	scanf("%d", &k);

	if (k == 1)
	{
		// Loop for Inserting the Element
		for (i = used_size - 1; i >= index - 1; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[index - 1] = element;

		// Print the new Element
		printf("New elements are : ");
		for (i = 0; i <= used_size; i++)
		{
			printf("%d\t", arr[i]);
		}
	}
	else if (k == 2)
	{
		anotherinsertion(arr, used_size, element, index);
	}
	else
		printf("Nothing Match");
}

void deletion(int arr[], int used_size)
{
	int del, i;
	printf("Enter the position of the element which you want to delete : ");
	scanf("%d", &del);

	// Deleting the element
	for (i = del; i <= used_size; i++)
	{
		arr[i - 1] = arr[i];
	}
	used_size = used_size - 1;

	// Print the new Array
	printf("New elements are : ");
	for (i = 0; i <=used_size; i++)
	{
		printf("%d\t", arr[i]);
	}
}

int main()
{
	int total_size, used_size;
	printf("Enter the total size of the array : ");
	scanf("%d", &total_size);
	int arr[total_size];
	printf("Enter the total no of elements : ");
	scanf("%d", &used_size);
	int check;
    do
    {
        printf("\n1.Traversal\n2.Insertion\n3.Deletion\n4.Quit\n**Choose Your Option** : ");
        scanf("%d", &check);
        switch (check)
        {
        case 1:
            traversal(arr, used_size);
            break;
        case 2:
            insertion(arr, used_size);
            break;
        case 3:
            deletion(arr, used_size);
            break;
        default:
            if (check != 4)
            {
                printf("\nInvalid Choice`~`\n");
            }
            break;
        }

    } while (check != 4);
}