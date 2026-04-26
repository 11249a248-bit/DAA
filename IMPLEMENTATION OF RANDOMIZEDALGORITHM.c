#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exchange(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int split(int data[], int start, int end)
{
    int pivotValue = data[end];
    int pos = start - 1;

    for (int k = start; k < end; k++)
    {
        if (data[k] < pivotValue)
        {
            pos++;
            exchange(&data[pos], &data[k]);
        }
    }

    exchange(&data[pos + 1], &data[end]);
    return pos + 1;
}

void sortRandom(int data[], int left, int right)
{
    if (left < right)
    {
        int idx = left + rand() % (right - left + 1);
        exchange(&data[idx], &data[right]);

        int mid = split(data, left, right);

        sortRandom(data, left, mid - 1);
        sortRandom(data, mid + 1, right);
    }
}

int main()
{
    int size;
    srand(time(NULL));

    printf("Enter size: ");
    if (scanf("%d", &size) != 1 || size <= 0)
        return 1;

    int arr[size];

    printf("Enter elements: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    sortRandom(arr, 0, size - 1);

    printf("Sorted: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
