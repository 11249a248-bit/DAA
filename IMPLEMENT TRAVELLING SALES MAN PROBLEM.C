#include <stdio.h>
#include <limits.h>

#define MAXN 15
#define INF INT_MAX

int N;
int D[MAXN][MAXN];
int DP[MAXN][1 << MAXN];

int G(int I, int S)
{
    if (S == 0)
        return D[I][0];

    if (DP[I][S] != -1)
        return DP[I][S];

    int MINCOST = INF;

    for (int K = 0; K < N; K++)
    {
        if (S & (1 << K))
        {
            int COST = D[I][K] + G(K, S & ~(1 << K));
            if (COST < MINCOST)
            {
                MINCOST = COST;
            }
        }
    }

    return DP[I][S] = MINCOST;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &N);

    printf("Enter cost matrix:\n");
    for (int I = 0; I < N; I++)
        for (int J = 0; J < N; J++)
            scanf("%d", &D[I][J]);

    for (int I = 0; I < N; I++)
        for (int MASK = 0; MASK < (1 << N); MASK++)
        {
            DP[I][MASK] = -1;
        }

    int S = 0;
    for (int I = 1; I < N; I++)
        S |= (1 << I);

    int RESULT = G(0, S);

    printf("Given Cost Matrix\n");
    for (int I = 0; I < N; I++)
    {
        printf("|");
        for (int J = 0; J < N; J++)
            printf(" %d ", D[I][J]);
        printf("|\n");
    }

    printf("Minimum travelling cost: %d\n", RESULT);

    return 0;
}
