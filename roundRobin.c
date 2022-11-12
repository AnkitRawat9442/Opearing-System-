#include<stdio.h>
int queue[100] ;
int front ;
int  end;
int rr_index;
//int rr[100];
void startQueue( int at[]  , int size)
{
    front = 1;
    end = 0;
    for(int i =1 ;i<=size;i++)
    {
        if(at[i] == 0)
        queue[++end]=i;
    }
    printf("Front : %d\tend : %d\n" , front , end);

}
int max_At (int at[]  , int n )
{
    int max = at[0] ;
    for(int i = 2 ;i<= n ;i++)
    {
      if(max < at[i])
        max = at[i];
    }
    return max ;
}

void queueAtRRIndex(int at[] , int n )
{ 
    rr_index++;
   if(rr_index <= max_At(at , n) )
   {
     for(int i = 1 ;i<= n ;i++)
    {
        if(at[i] == rr_index)
        {
            queue[++end] =i;
        }
    }
   }
}


void roundRobin(int at[]  , int bt[] , int n )
{
    
    while(end >= front)
    {
         int cur = queue[front];
      printf("P%d ",queue[cur]);
      bt[cur]--;
      queueAtRRIndex(at , n );
     
      if(bt[cur] != 0)
      {
       queue[++end] = queue[front++];
      }
      else{
        front++;
      }
      
    }
}

int main()
{
  int n ;
 // front = 0 , end = 0 ;
  printf("Enter the number of the process : ");
  scanf("%d",&n);
  int at[n] , bt[n];
  printf("Enter the Arrival time And Brust time \n");
for( int i = 1 ;i<=n ;i++)
  {
    scanf("%d",&at[i]);
    scanf("%d",&bt[i]);
  }

for( int i = 1 ;i<=n ;i++)
{
    printf("P%d\t%d\t%d\n", i , at[i] , bt[i]);
}

startQueue(at , n);



for( int i = 1 ;i<=end ;i++)
{
    printf("P%d\n",  queue[i]);
}
  roundRobin(at , bt , n );
    return 0;
}



