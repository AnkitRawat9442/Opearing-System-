#include<stdio.h>
#include<stdlib.h.>

struct process {
    int pid , at , bt , pri ,ct ,  tat , wt , rt , st , rbt ;
}ps[100];

int main ()
{
    int n ;
    printf("Enter the val of n : ");
    scnaf("%d" , &n);
    for(int i =0 ;i< n ;i++)
    {
        scanf("%d%d%d" , &ps[i].at , &ps[i].bt , &ps[i].pri);
        ps[i].pid = i;       // process id 
        ps[i].rbt = ps[i].bt;  // inital remaining brust time = brust time 
    }
    
    int curtime = 0 ;
    int completed = 0 ;  // number of process completed
    int iscompleted[100] = {0};  // status of process either completed or not 
    while(completed != n )
    {
        int maxpri = -1 ;
        int maxpriindex =  -1 ;
        for(int i =0 ;i<n ;i++)
        {
           if(ps[i].at <=  curtime && iscompleted[i] == 0 ) 
           {
             if(ps[i].pri > maxpri)
             {
                maxpri = ps[i].pri;
                maxpriindex = i;
             }
           }
        }
      
       if(maxpriindex == -1 )
       {
          curtime++;
       }else{
          
            
         ps[maxpriindex].rbt--;
         curtime++;
         
         if(ps[maxpriindex].rbt  == 0)
         {
            ps[maxpriindex].ct =curtime;
            ps[maxpriindex].tat = ps[maxpriindex].ct -ps[maxpriindex].at;
            ps[maxpriindex].wt = ps[maxpriindex].tat -ps[maxpriindex].bt;

            iscompleted[maxpriindex]= 1;
            completed++; 
         }


       }


    }


 
}


