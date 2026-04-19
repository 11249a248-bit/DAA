#include<stdio.h>

struct item
{
    int PROFIT;
    int WEIGHT;
    float RATIO;
};

void sort(struct item items[], int N)
{
    struct item temp;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (items[j].RATIO < items[j + 1].RATIO)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int C, N;
    printf("enter capacity:");
    scanf("%d", &C);

    printf("enter no of items:");
    scanf("%d", &N);

    struct item itm[N];

    for (int i = 0; i < N; i++)
    {
        printf("enter item %d weight profit:", i + 1);
        scanf("%d %d", &itm[i].WEIGHT, &itm[i].PROFIT);
        itm[i].RATIO = (float)itm[i].PROFIT / itm[i].WEIGHT;
    }

    sort(itm, N);

    float TOTALPROFIT = 0.0;

    for (int i = 0; i < N; i++)
    {
        if (C >= itm[i].WEIGHT)
        {
            TOTALPROFIT += itm[i].PROFIT;
            C -= itm[i].WEIGHT;
        }
        else
        {
            TOTALPROFIT += itm[i].RATIO * C;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", TOTALPROFIT);

    return 0;
}
