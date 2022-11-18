// non preemptive Shortest job First Scheduling

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct process
{
    int pid, at, bt, ct, tat, wt, st, rt , rbt;
} ps[100];

int findmax(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    int n;
    printf("Enter the no of process : ");
    scanf("%d", &n);
    printf("Enter the process AT and BT \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &ps[i].at, &ps[i].bt);
        ps[i].pid = i;
        ps[i].rbt = ps[i].bt ;
    }

    float sum_tat = 0, sum_rt = 0, sum_wt = 0, total_idle_time = 0, total_time = 0, utilisation = 0;
    int completed = 0;
    bool is_completed[100] = {false};
    bool is_first_ps = true;
    int curtime = 0, pre = 0;
    while (completed != n)
    {
        int minbt = 32000;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (ps[i].at <= curtime && is_completed[i] == false)
            {
                if (minbt > ps[i].rbt)
                {
                    minbt = ps[i].rbt;
                    index = i;
                }
                if (minbt == ps[i].rbt)
                {
                    if (ps[i].at < ps[index].at)
                    {
                        minbt = ps[i].rbt;
                        index = i;
                    }
                }
            }
        }

        if (index == -1)
        {
            curtime++;
        }
        else
        {
             
             if(ps[index].bt == ps[index].rbt)
            {
                ps[index].st = curtime;
                total_idle_time += is_first_ps == true ? 0 : ps[index].st - pre;
                is_first_ps = false;
            }
            
            ps[index].rbt--;
            curtime++;
            pre = curtime;

            if(ps[index].rbt == 0)
            {
             
            ps[index].ct = curtime;
            ps[index].tat = ps[index].ct - ps[index].at;
            ps[index].wt = ps[index].tat - ps[index].bt;
            ps[index].rt = ps[index].wt;

            sum_rt += ps[index].rt;
            sum_tat += ps[index].tat;
            sum_wt += ps[index].wt;

          
            
            completed++;
            is_completed[index] = true;
           
            }

        }
    }

    
    for( int i = 0 ;i<n  ;i++)
    {
        total_time = findmax(total_time , ps[i].ct);
    }
    

    total_time = ps[n - 1].ct;
    utilisation = (total_time - total_idle_time) / total_time;

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt);
    }
    printf("Average rT : \t%f\nAverage TAT : \t%f\nAverage WT : \t%f\n", sum_rt / n, sum_tat / n, sum_wt / n);
    printf("ThroughPut : %f\n", n / total_time);
    printf("CPU Utilisation : %.2f %%\n ", utilisation * 100);
    return 0;
}
