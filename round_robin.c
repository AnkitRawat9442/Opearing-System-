#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h.>



struct process 
{
  int pid , at , bt , tat , ct , wt , rt , st , rbt ;

} ps[100]  ;



int comparatorAt ( const void * a , const void * b )
{
    int x =  ((struct process *)a)->at ;
    int y =   ((struct process *)b)->at ;
    if(x < y )  return - 1;  // no sorting 
    else if( x>= y ) return 1 ; // sorting 
}

int findmax(int x , int y )
{
    return (x>y )? x :y ;
}

int main ()
{
    int n , tq  ;
    printf("Enter n : ");
    scanf("%d" , &n );

    for(int i =0 ;i< n ;i++)
    {
        printf("Process %d at and bt : ", i+1);
        scanf("%d%d" , &ps[i].at , &ps[i].bt);
        ps[i].pid = i ;
        ps[i].rbt = ps[i].bt;   //initial  remaining bt = bt 
    }

    printf("Enter the time qunata : ")    ;
    scanf("%d" , &tq);

    // before  sort 
   qsort ((void *)ps , n ,sizeof(struct process)  , comparatorAt );
    // after sort 

    int completed = 0 ;// number of process completed 
    int visited[100] = {0} ;    // status to show that process is entered in queue or not 
    int curtime = 0 ;
    int queue [100] ;    // fifo
    int front = -1 ,  rear = -1 ; //empty queue
    int index  ;
    
    front = 0 ;
     rear = 0 ;
    queue[0] = 0 ;   
    visited[0] = 1 ;
 
   
  
    
    while(completed != n )
    {
       index = queue[front];
       front++;

      if(ps[index].rbt == ps[index].bt)   // process is coming for the first time 
      {
         ps[index].st = findmax(ps[index].at , curtime );
         curtime = ps[index].st;
      }

     if(ps[index].rbt > tq)
     {
        ps[index].rbt =  ps[index].rbt -  tq;
        curtime += tq;
     }
     else
     {
        curtime += ps[index].rbt;
        ps[index].rbt = 0 ;
        completed++;
        
        ps[index].ct = curtime ;
        ps[index].tat = ps[index].ct - ps[index].at;
        ps[index].wt = ps[index].tat - ps[index].bt;
     }


    for( int i =0  ;i< n ;i++)
    {
        if(ps[i].rbt > 0 && ps[i].at <= curtime && visited[i] == 0)
        {
             queue[++rear] = i;
             visited[i]  = 1;
        }
    }
     if(ps[index].rbt > 0)  
     {
        queue[++rear] = index;
     
     }
    
 
    
    }

  
  for(int i =0 ;i<n ;i++)
  {
     printf("Process %d\t%d\t%d\t%d\t%d\t%d\n" , ps[i].pid , ps[i].at , ps[i].bt , ps[i].ct , ps[i].tat , ps[i].wt);
  }
  

    return 0 ;
}