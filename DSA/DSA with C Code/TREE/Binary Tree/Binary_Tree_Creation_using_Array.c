
#include <stdio.h>

int tree[10000], i = 1;

int create()
{
    int x;
    printf("Enter Left Child of %d .. Press -1 for no child = ", tree[i]);
    scanf("%d", &x);
    if(x!=-1)
    {
        tree[2*i]=x;
    }
    else{
        tree[2*i]='\0';
    }
    printf("Enter Right Child of %d .. Press -1 for no child = ", tree[i]);
    scanf("%d", &x);
    if(x!=-1)
    {
        tree[2*i+1]=x;
    }
    else{
        tree[2*i+1]='\0';
    }
    i++;
}

int main()
{
    int x;
    printf("\nEnter Root Data or Press -1 for no Data = ");
    scanf("%d", &x);
    if (x == -1)
    {
        printf("\n`~` Tree is Empty `~`");
        return 0;
    }
    tree[i] = x;
    int ch;
    do
    {
        if (tree[(2 * (i - 1))] == -1 && tree[(2 * (i - 1)) + 1] == -1)
        {
            printf("\n**\tTree is Ready\t**");
            return 0;
        }
        printf("\n** Are you insert next data in Binary Tree **\n1.Yes\n2.No\nEnter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;

        default:
            if (ch != 2)
            {
                printf("\n`~`Invalid Choice`~`");
            }
            break;
        }
    } while (ch != 2);
    printf("\n**\tTree is Ready\t**\n");
    for(int j=1;j!=(i-1);j++)
    {
        printf("%d %d %d",tree[j],tree[2*j],tree[2*j+1]);
    }
}