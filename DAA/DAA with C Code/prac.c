#include <stdio.h>

void merge(float *weight, float *profit, float *ratio, int lb,int mid, int ub)
{
    int i=lb,j=mid+1,k=lb;
    float weight1[10000],profit1[10000],ratio1[10000];

    while (i<=mid && j<=ub)
    {
        if (ratio[i]>=ratio[j])
        {
            ratio1[k]=ratio[i];
            profit1[k]=profit[i];
            weight1[k]=weight[i];
            i++;
        }
        else{
            ratio1[k]=ratio[j];
            profit1[k]=profit[j];
            weight1[k]=weight[j];
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        while (j<=ub)
        {
            ratio1[k]=ratio[j];
            profit1[k]=profit[j];
            weight1[k]=weight[j];
            j++;
            k++;
        }
    }
    else{
        while (i<=mid)
        {
            ratio1[k]=ratio[i];
            profit1[k]=profit[i];
            weight1[k]=weight[i];
            i++;
            k++;
        }
    }

    for (int i = 0; i < ub; i++)
    {
        ratio[i]=ratio1[i];
        weight[i]=weight[i];
        profit[i]=profit1[i];
    }
}

void mergesort(float *weight, float *profit, float *ratio, int lb, int ub)
{
    if (lb > ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(weight, profit, ratio, lb, mid);
        mergesort(weight, profit, ratio, mid + 1, ub);
        merge(weight, profit, ratio, lb, mid, ub);
    }
}

void knapsack(float *weight, float *profit, int capacity, int n)
{
    float x[n],totalprof=0.0;
    int U=capacity;

    for (int i = 0; i < n; i++)
    {
        x[i]=0.0;
    }

    int j;

    for (j = 0; j < n; j++)
    {
        if(weight[j]>U)
        {
            break;
        }
        else{
            x[j]=1.0;
            totalprof=totalprof+profit[j];
            U=U-weight[j];
        }
    }

    if(j<n)
    {
        x[j]=U/weight[j];
    }

    totalprof=totalprof+(x[j]*profit[j]);
    
    printf("%f",totalprof);
    
}

int main()
{
    int n;
    scanf("%d", &n);
    float profit[n], weight[n], ratio[n];

    for (int i = 0; i < n; i++)
    {
        printf("Object%d Weight = ", i + 1);
        scanf("%f", &weight[i]);
        printf("Object%d Profit = ", i + 1);
        scanf("%f", &profit[i]);

        ratio[i] = profit[i] / weight[i];
    }

    int capacity;
    scanf("%d", &capacity);
    int lb = 0, ub = n - 1;
    mergesort(weight, profit, ratio, lb, ub);

    knapsack(weight, profit, capacity, n);
}