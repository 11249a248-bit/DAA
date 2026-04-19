#include <stdio.h>
int fibbonaci(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fibbonaci(n-1)+fibbonaci(n-2);
}

int main()
{
    int n;
    printf("enter number: ");
    scanf("%d",&n);

    if (n < 0) {
        printf("invalid");
    }

    printf("fibonacci term is: %d", fibbonaci(n));
    return 0;
}
