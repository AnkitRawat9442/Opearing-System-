
#include<stdio.h>

typedef struct process {
  int pid;
  int at , bt , ct , rt ,tat , bt_remaining , start_time;
}PR;

int main()
{
    int n ;
    PR P[100] ;
    printf("Enter the number of process : ");
    scanf("%n", &n);
    
    printf("Enter the Arrival time and Brust Time  \n ");
    for(int i =0 ;i <n ;i++)
    {
        printf("For Process %d : ", i+1);
        scanf("%d%d", &P[i].at ,&P[i].bt);
        

        
    }

}