#include <stdio.h>

void TOHH(int disk_count, char s, char d, char t)
{
    if (disk_count == 1)
    {
        printf("\nMove disk %d from %c to %c", disk_count, s, d);
        return;
    }

    TOHH(disk_count - 1, s, t, d);
    printf("\nMove disk %d from %c to %c", disk_count, s, d);
    TOHH(disk_count - 1, t, d, s);
}

int main()
{
    int n;
    printf("enter number of disks: ");
    scanf("%d", &n);

    TOHH(n, 's', 'd', 't');
    return 0;
}
