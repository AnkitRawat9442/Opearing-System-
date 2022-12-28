#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Process
{
    int pid, at, bt, ct, tat, wt, rt, st, prio, rbt;

} PS[100];

int findmax(int a, int b)
{
    return (a > b) ? a : b;
}
int findmin(int a, int b)
{
    return (a < b) ? a : b;
}
int main()
{
    int n;
    printf("Enter the Number of the process :  ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &PS[i].at, &PS[i].bt, &PS[i].prio);
        PS[i].pid = i;
        PS[i].rbt = PS[i].bt;
    }
    int completed = 0, current = 0, prev = 0;
    bool iscompleted[100] = {false};

    float total_time = 0, idle_time = 0, utilisation = 0;

    float sum_ct = 0, sum_tat = 0, sum_wt = 0, sum_rt = 0;
    bool is_first_proces = true;

    while (completed != n)
    {

        int max_prio = -32000, index = -1;
        for (int i = 0; i < n; i++)
        {
            if (PS[i].at <= current && iscompleted[i] == false)
            {
                if (PS[i].prio > max_prio)
                {
                    max_prio = PS[i].prio;
                    index = i;
                }
                else if (PS[i].prio == max_prio)
                {
                    if (PS[i].at < PS[index].at)
                    {
                        max_prio = PS[i].prio;
                        index = i;
                    }
                }
            }
        }
       
        if (index == -1)
        {
            current++;
        }
        else
        {
            if (PS[index].rbt == PS[index].bt)
            {
                PS[index].st = current;
                idle_time += is_first_proces == true ? 0 : PS[index].st - prev;
                is_first_proces = false;
            }

            PS[index].rbt--;
            current++;
            prev = current;

          if(PS[index].rbt == 0)
          {
              PS[index].st = current;
            PS[index].ct = PS[index].st + PS[index].bt;
            PS[index].tat = PS[index].ct - PS[index].at;
            PS[index].wt = PS[index].tat - PS[index].bt;
            PS[index].rt = PS[index].st - PS[index].at;
            sum_ct += PS[index].ct;
            sum_tat += PS[index].tat;
            sum_wt += PS[index].wt;
            sum_rt += PS[index].rt;
            iscompleted[index]= true ;
            completed++;
          }
        }
    }
     int maxct = 0 , minat = 0 ;
    for (int i = 0; i < n; i++)
    {
       maxct = findmax(maxct , PS[i].ct) ;
       minat = findmin(minat , PS[i].at);
    }

    total_time = maxct - minat;
    
    utilisation = (float)(total_time - idle_time) / total_time;

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t" , PS[i].pid , PS[i].at , PS[i].bt , PS[i].ct , PS[i].tat , PS[i].wt);
        printf("\n");
    }
 

   printf("Avg CT : %f\n", (sum_ct)/n);
   printf("Avg TAT : %f\n", (sum_tat)/n);
   printf("Avg WT : %f\n", (sum_wt)/n);
  


    printf("Idle time : %f\n", idle_time);
    printf("Utilisation : %f\n", utilisation);

    return 0;
}