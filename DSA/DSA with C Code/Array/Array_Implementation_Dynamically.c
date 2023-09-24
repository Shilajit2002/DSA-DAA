#include<stdio.h>
#include<stdlib.h>

struct Array
{
	int total_size;
	int used_size;
	int *ptr;
};

void create_array(struct Array *a)
{
	printf("Plz enter the total size of an Array: ");
	scanf("%d",&a->total_size);
	printf("Plz enter the used size of an Array: ");
	scanf("%d",&a->used_size);
	a->ptr=(int*)malloc(a->total_size*sizeof(int));
}

void set_val(struct Array *a)
{
	int n;
	printf("Plz enter any %d nos. in the Array : ",a->used_size);
	for(int i=0;i<a->used_size;i++)
	{
		scanf("%d",&n);
		(a->ptr)[i]=n;
	}
}

void show(struct Array *a)
{
	for(int i=0;i<a->used_size;i++)
	{
		printf("%d\t",(a->ptr)[i]);
	}
}

int main()
{
	struct Array Hello;
	printf("**We are Creating the Array**\n");
	create_array(&Hello);
	printf("**We are Setting the value of the Array**\n");
	set_val(&Hello);
	printf("**We are Printing the value of the Array**\n");
	show(&Hello);
}
