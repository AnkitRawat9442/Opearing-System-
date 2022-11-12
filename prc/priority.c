#include<stdio.h>
#include<stdlib.h>

struct process {
    int pid , at , bt , pri , ct , tat , wt , rt , st , rbt ;
}ps[100];


int main ()

{
    int n ;
    printf("enter the n : ");
    scanf("%d" , &n );

    for ( int i = 0 ; i < n ;i++)
   {
      scanf("%d%d%d" , &ps[i].at , &ps[i].bt , &ps[i].pri);
      ps[i].pid = i;
      ps[i].rbt = ps[i].bt;
   }

   int completed = 0 ;
   int iscompleted [100] = {0};
   int curtime = 0 ;
   while(completed != n )
   {
       int maxpri = -1 ;
       int maxpriindex = -1;
       for(int i = 0;i<n ;i++){
        if(ps[i].at <= curtime && ps[i].rbt > 0  && iscompleted[i] == 0 )
        {
            if(ps[i].pri > maxpri)
            {
                maxpri = ps[i].pri;
                maxpriindex = i;
            }
            if(ps[i].pri == maxpri)
            {
                if(ps[i].at < ps[maxpriindex].at)
                {
                  maxpri = ps[i].pri;
                  maxpriindex = i ;
                }
            }
        }
       }

       if(maxpriindex == -1)
       {
          curtime++;
       }
       else{
           if( ps[maxpriindex].rbt == ps[maxpriindex].bt)
           {
             ps[maxpriindex].st = curtime;
           }
           ps[maxpriindex].rbt--;
           curtime++;
           if(ps[maxpriindex].rbt == 0 )
           {
             ps[maxpriindex].ct = curtime;
             ps[maxpriindex].tat = ps[maxpriindex].ct - ps[maxpriindex].at;
             ps[maxpriindex].wt = ps[maxpriindex].tat - ps[maxpriindex].bt;
             ps[maxpriindex].rt = ps[maxpriindex].st -  ps[maxpriindex].at;
           completed++;
          iscompleted[maxpriindex] = 1 ;
           }
          
       }
        
   }
 for ( int i = 0 ; i < n ;i++)
   {
     printf("%d\t%d\t%d\t%d\n" , ps[i].ct ,ps[i].tat , ps[i].wt , ps[i].rt );
   }

   


   return 0 ;
}




