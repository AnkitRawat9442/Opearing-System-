#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct process {
    int pid , at , bt , ct , tat , wt , st , rbt ;
}ps[100];

int main ()
{
   int n ;
   printf("Enter the value of the n : ");
   scanf("%d" , &n );

   for(int i =0 ;i<n ;i++)
   {
    scanf("%d%d" , &ps[i].at , &ps[i].bt );
    ps[i].pid = i ;
    ps[i].rbt = ps[i].bt;
   }
   int completed = 0 ;
   int iscompleted[100] = {0};
   int curtime = 0 ;
  
   while(completed != n )
   {                     
       int min  = INT_MAX ;
       int minindex = -1 ;
      for(int i =0 ; i<n ;i++)
      {
        if(ps[i].at <= curtime && iscompleted[i] == 0)
        {
            if(ps[i].rbt < min)
            {
                min = ps[i].rbt;
                minindex = i;
            }
            if(ps[i].rbt == min)
            {
                if(ps[i].at < ps[minindex].at)
                {
                    min = ps[i].rbt;
                    minindex = i;
                }
            }
        }
      }
     if(minindex  == -1)
     {
        curtime++;
     }
     else{
        ps[minindex].rbt--;
        curtime++;
        printf("P%d ", ps[minindex].pid);
        if(ps[minindex].rbt == 0)
        {
            ps[minindex].ct = curtime;
             ps[minindex].tat =  ps[minindex].ct -  ps[minindex].at;
              ps[minindex].wt =  ps[minindex].tat -  ps[minindex].bt;
            completed++;
            iscompleted[minindex] = 1;
        }
     }

   }
   
   
  printf("\n");
   printf("P-No\tAt\tBT\tCT\tTAT\tWT\n");
  for(int i =0 ;i< n ;i++)
  {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n " ,ps[i].pid ,ps[i].at , ps[i].bt ,  ps[i].ct , ps[i].tat , ps[i].wt);
  }



  return 0 ;

}

