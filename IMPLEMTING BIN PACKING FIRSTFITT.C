#include<stdio.h>

void FIRSTFIT(int ITEMS[],int N,int C)
{
int BIN[N];
int BINCOUNT=0;
for(int I=0;I<N;I++)
BIN[I]=C;
for(int I=0;I<N;I++)
{
int PLACED=0;
for(int J=0;J<BINCOUNT;J++)
{
if(BIN[J]>=ITEMS[I])
{
BIN[J]-=ITEMS[I];
printf("item %d placed in bin %d\n",ITEMS[I],J+1);
PLACED=1;
break;
}
}
if(!PLACED)
{
BIN[BINCOUNT]-=ITEMS[I];
printf("item %d placed in bin %d\n",ITEMS[I],BINCOUNT+1);
BINCOUNT++;
}
}
printf("total bins used =%d\n",BINCOUNT);
}

int main()
{
int N,C;
printf("enter number of items: ");
scanf("%d",&N);
int ITEMS[N];
printf("enter item size:\n");
for(int I=0;I<N;I++)
{
printf("item %d:",I+1);
scanf("%d",&ITEMS[I]);
}
printf("enter bin capacity: ");
scanf("%d",&C);
FIRSTFIT(ITEMS,N,C);
return 0;
}
