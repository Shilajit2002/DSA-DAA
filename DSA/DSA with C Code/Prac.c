#include <stdio.h>

void Merge(float *ratio, float *weight, float *profit, int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    float ratio1[100000], weight1[100000], profit1[100000];

    while (i <= mid && j <= ub)
    {
        if (ratio[i] >= ratio[j])
        {
            ratio1[k] = ratio[i];
            weight1[k] = weight[i];
            profit1[k] = profit[i];
            i++;
        }
        else
        {
            ratio1[k] = ratio[j];
            weight1[k] = weight[j];
            profit1[k] = profit[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            ratio1[k] = ratio[j];
            weight1[k] = weight[j];
            profit1[k] = profit[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            ratio1[k] = ratio[i];
            weight1[k] = weight[i];
            profit1[k] = profit[i];
            i++;
            k++;
        }
    }

    for (k = 0; k <= ub; k++)
    {
        ratio[k] = ratio1[k];
        weight[k] = weight1[k];
        profit[k] = profit1[k];
    }
}

void Merge_Sort(float *ratio, float *weight, float *profit, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        Merge_Sort(ratio, weight, profit, lb, mid);
        Merge_Sort(ratio, weight, profit, mid + 1, ub);
        Merge(ratio, weight, profit, lb, mid, ub);
    }
}

void Knapsack(float *profit, float *weight, float capacity, int n)
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
        if (weight[j] > U)
        {
            break;
        }
        else
        {
            x[j] = 1.0;
            Total_Profit = Total_Profit + profit[j];
            U = U - weight[j];
        }
    }

    if (j < n)
    {
        x[j] = U / weight[j];
    }

    Total_Profit = Total_Profit + (x[j] * profit[j]);

    // Maximum Profit
    printf("\n\nMaximum Profit is = %.2f", Total_Profit);
}

int main()
{
    int n;
    printf("Enter the total no. of Objects = ");
    scanf("%d", &n);

    float weight[n], profit[n], ratio[n];
    float capacity;

    // For Object's Weight & Profits
    for (int i = 0; i < n; i++)
    {
        printf("Enter Object-%d Weight = ", i + 1);
        scanf("%f", &weight[i]);

        printf("Enter Object-%d Profit = ", i + 1);
        scanf("%f", &profit[i]);
    }

    // Calculate the ratio of Profit/Weight
    for (int i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // Knapsack Capacity
    printf("Enter the Knapsack Capacity = ");
    scanf("%f", &capacity);

    // Sort the Objects As Per Ratio Using Merge Sort
    int lb = 0, ub = n - 1;
    Merge_Sort(ratio, weight, profit, lb, ub);

    // knapsack Problem..find the maximum profit
    Knapsack(profit, weight, capacity, n);
}