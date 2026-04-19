#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define SIZE 5

int FINDMIN(int KEYS[], bool INCLUDED[]) {
int MINVAL = INT_MAX, INDEX;

for (int X = 0; X < SIZE; X++)
    if (INCLUDED[X] == false && KEYS[X] < MINVAL)
        MINVAL = KEYS[X], INDEX = X;

return INDEX;
}

void SHOWMST(int PARENT[], int MATRIX[SIZE][SIZE]) {
printf("Edge \tWeight\n");
for (int X = 1; X < SIZE; X++)
printf("%d - %d \t%d \n", PARENT[X], X, MATRIX[PARENT[X]][X]);
}

void PRIMSALGO(int MATRIX[SIZE][SIZE]) {
int PARENT[SIZE];
int KEYS[SIZE];
bool INCLUDED[SIZE];

for (int X = 0; X < SIZE; X++)
    KEYS[X] = INT_MAX, INCLUDED[X] = false;

KEYS[0] = 0;
PARENT[0] = -1;

for (int COUNT = 0; COUNT < SIZE - 1; COUNT++) {
    int U = FINDMIN(KEYS, INCLUDED);
    INCLUDED[U] = true;

    for (int Y = 0; Y < SIZE; Y++)
        if (MATRIX[U][Y] && INCLUDED[Y] == false && MATRIX[U][Y] < KEYS[Y])
            PARENT[Y] = U, KEYS[Y] = MATRIX[U][Y];
}

SHOWMST(PARENT, MATRIX);
}

int main() {
int MATRIX[SIZE][SIZE] = {
{ 0, 2, 0, 6, 0 },
{ 2, 0, 3, 8, 5 },
{ 0, 3, 0, 0, 7 },
{ 6, 8, 0, 0, 9 },
{ 0, 5, 7, 9, 0 }
};

PRIMSALGO(MATRIX);

return 0;
}
