#include <stdio.h>

#define N 5

void approxCover(int adj[N][N]) {
    int mark[N];

    for (int i = 0; i < N; i++) {
        mark[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj[i][j] == 1 && !mark[i] && !mark[j]) {
                mark[i] = 1;
                mark[j] = 1;
         }
        }
        }

    printf("Vertex Cover (Approx): ");
    int total = 0;

    for (int i = 0; i < N; i++) {
        if (mark[i]) {
            printf("%d ", i);
            total++;
    }
    }

    printf("\nCount: %d\n", total);
}

int main() {
    int matrix[N][N] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Running Approximation...\n");

    approxCover(matrix);
    return 0;
}
