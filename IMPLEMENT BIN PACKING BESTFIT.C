#include<stdio.h>
void BESTFIT(int ITEMS[],int N,int CAPACITY){
int BIN[N];
int BINCOUNT=0;
for(int I=0;I<N;I++)BIN[I]=CAPACITY;
for(int I=0;I<N;I++){
int BESTINDEX=-1;
int MINSPACE=CAPACITY+1;
for(int J=0;J<BINCOUNT;J++){
if(BIN[J]>=ITEMS[I]&&(BIN[J]-ITEMS[I])<MINSPACE){
BESTINDEX=J;
MINSPACE=BIN[J]-ITEMS[I];
}}
if(BESTINDEX!=-1){
BIN[BESTINDEX]-=ITEMS[I];
printf("Item %d (weight %d) placed in Bin %d\n",I+1,ITEMS[I],BESTINDEX+1);
}else{
BIN[BINCOUNT]-=ITEMS[I];
printf("Item %d (weight %d) placed in Bin %d\n",I+1,ITEMS[I],BINCOUNT+1);
BINCOUNT++;
}}
printf("Total bins used = %d\n",BINCOUNT);
}
int main(){
int N,CAPACITY;
printf("Enter number of items: ");
scanf("%d",&N);
int ITEMS[N];
printf("Enter bin capacity: ");
scanf("%d",&CAPACITY);
printf("Enter item sizes:\n");
for(int I=0;I<N;I++){
int ITEMSIZE;
printf("Item %d: ",I+1);
scanf("%d",&ITEMSIZE);
if(ITEMSIZE<=CAPACITY){
ITEMS[I]=ITEMSIZE;
}else{
printf("Item size exceeds bin capacity. Please enter again.\n");
I--;
}}
BESTFIT(ITEMS,N,CAPACITY);
return 0;
}
