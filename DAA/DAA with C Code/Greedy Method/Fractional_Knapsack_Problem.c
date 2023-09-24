#include <stdio.h>

struct FKP
{
    char obj[100];
    float weight, profit, ratio;
};

void Merge(struct FKP *sack, int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb,L;
    struct FKP sack1[100000];

    while (i <= mid && j <= ub)
    {
        if (sack[i].ratio >= sack[j].ratio)
        {
            sack1[k].ratio = sack[i].ratio;
            sack1[k].weight = sack[i].weight;
            sack1[k].profit = sack[i].profit;
            for (L = 0; sack[i].obj[L] != '\0'; L++)
            {
                sack1[k].obj[L] = sack[i].obj[L];
            }
            sack1[k].obj[L] = sack[i].obj[L];
            i++;
        }
        else
        {
            sack1[k].ratio = sack[j].ratio;
            sack1[k].weight = sack[j].weight;
            sack1[k].profit = sack[j].profit;
             for (L = 0; sack[j].obj[L] != '\0'; L++)
            {
                sack1[k].obj[L] = sack[j].obj[L];
            }
            sack1[k].obj[L] = sack[j].obj[L];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            sack1[k].ratio = sack[j].ratio;
            sack1[k].weight = sack[j].weight;
            sack1[k].profit = sack[j].profit;
            for (L = 0; sack[j].obj[L] != '\0'; L++)
            {
                sack1[k].obj[L] = sack[j].obj[L];
            }
            sack1[k].obj[L] = sack[j].obj[L];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            sack1[k].ratio = sack[i].ratio;
            sack1[k].weight = sack[i].weight;
            sack1[k].profit = sack[i].profit;
            for (L = 0; sack[i].obj[L] != '\0'; L++)
            {
                sack1[k].obj[L] = sack[i].obj[L];
            }
            sack1[k].obj[L] = sack[i].obj[L];
            i++;
            k++;
        }
    }

    for (k = 0; k <= ub; k++)
    {
        sack[k].ratio = sack1[k].ratio;
        sack[k].weight = sack1[k].weight;
        sack[k].profit = sack1[k].profit;
        for (L = 0; sack1[k].obj[L] != '\0'; L++)
            {
                sack[k].obj[L] = sack1[k].obj[L];
            }
            sack[k].obj[L] = sack1[k].obj[L];;
    }
}

void Merge_Sort(struct FKP *sack, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        Merge_Sort(sack, lb, mid);
        Merge_Sort(sack, mid + 1, ub);
        Merge(sack, lb, mid, ub);
    }
}

void Knapsack(struct FKP *sack, float capacity, int n)
{
    float x[n], Total_Profit = 0;
    int U = capacity;

    for (int i = 0; i < n; i++)
    {
        x[i] = 0.00;
    }

    int j;
    for (j = 0; j < n; j++)
    {
        if (sack[j].weight > U)
        {
            break;
        }
        else
        {
            x[j] = 1.0;
            Total_Profit = Total_Profit + sack[j].profit;
            U = U - sack[j].weight;
        }
    }

    if (j < n)
    {
        x[j] = U / sack[j].weight;
    }

    Total_Profit = Total_Profit + (x[j] * sack[j].profit);

    // Printing Selecting Array..It is not required but you can print
    printf("\n\n\t** Array Profit Selector **\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %.1f |", x[i]);
    }

    // Maximum Profit
    printf("\n\nMaximum Profit is = %.2f", Total_Profit);
}

int main()
{
    int n;
    printf("Enter the total no. of Objects = ");
    scanf("%d", &n);

    struct FKP sack[n];

    float capacity;

    // For Object's Weight & Profits
    for (int i = 0; i < n; i++)
    {
        printf("Enter Object-%d Name = ", i + 1);
        scanf("%S", sack[i].obj);

        printf("Enter %S Weight = ", sack[i].obj);
        scanf("%f", &sack[i].weight);

        printf("Enter %S Profit = ", sack[i].obj);
        scanf("%f", &sack[i].profit);
    }

    // Calculate the ratio of Profit/Weight
    for (int i = 0; i < n; i++)
    {
        sack[i].ratio = sack[i].profit / sack[i].weight;
    }

    // Knapsack Capacity
    printf("Enter the Knapsack Capacity = ");
    scanf("%f", &capacity);

    // Print The Objects Table.It is not required but you can print
    printf("\n\n\t** Objects Table **\n");
    printf("Object\tWeight\tProfit\tRatio\n");
    for (int i = 0; i < n; i++)
    {
        printf("%S\t", sack[i].obj);
        printf("%.2f\t", sack[i].weight);
        printf("%.2f\t", sack[i].profit);
        printf("%.2f\n", sack[i].ratio);
    }

    // Sort the Objects As Per Ratio Using Merge Sort
    int lb = 0, ub = n - 1;
    Merge_Sort(sack, lb, ub);

    // After Sorting As per profit/weight Objects Table Print..Not required..
    printf("\n\n\t** After Sorting as Per Ratio **\n");
    printf("Object\tWeight\tProfit\tRatio\n");
    for (int i = 0; i < n; i++)
    {
        printf("%S\t", sack[i].obj);
        printf("%.2f\t", sack[i].weight);
        printf("%.2f\t", sack[i].profit);
        printf("%.2f\n", sack[i].ratio);
    }

    // knapsack Problem..find the maximum profit
    Knapsack(sack, capacity, n);
}