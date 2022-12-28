// Preemtive Priority CPU Scheduling 
// higher the value of priority higher is the priority of the process 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct process
{
    int pid, at, bt, pri, ct, tat, wt,rt , st, rbt;
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
    printf("Enter the process AT and BT and Priority \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &ps[i].at, &ps[i].bt, &ps[i].pri);
        ps[i].pid = i;
        ps[i].rbt = ps[i].bt;
    }
   
    float sum_tat = 0, sum_rt = 0, sum_wt = 0, total_idle_time = 0, total_time = 0, utilisation = 0;
    int completed = 0;
    bool is_completed[100] = {false};
    bool is_first_ps = true;
    int curtime = 0 , pre =0 ;

    while (completed != n)
    {
        int maxpri = -1;
        int maxpri_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (ps[i].at <= curtime && is_completed[i] == false)
            {
                if (ps[i].pri > maxpri)
                {
                    maxpri = ps[i].pri;
                    maxpri_index = i;
                }
                if (ps[i].pri == maxpri)
                {
                    if (ps[i].at < ps[maxpri_index].at)
                    {
                        maxpri = ps[i].pri;
                        maxpri_index = i;
                    }
                }
            }
        }
        if (maxpri_index == -1)
        {
            curtime++;
        }
        else
        {
            if(ps[maxpri_index].bt == ps[maxpri_index].rbt)
            {
                ps[maxpri_index].st = curtime;
                total_idle_time += is_first_ps == true ? 0 : ps[maxpri_index].st - pre;
                is_first_ps = false;
            }
            
            ps[maxpri_index].rbt--;
            curtime++;
            pre = curtime;
            if (ps[maxpri_index].rbt == 0)
            {
                ps[maxpri_index].ct = curtime;
                ps[maxpri_index].tat = ps[maxpri_index].ct - ps[maxpri_index].at;
                ps[maxpri_index].wt = ps[maxpri_index].tat - ps[maxpri_index].bt;
                ps[maxpri_index].rt = ps[maxpri_index].st - ps[maxpri_index].at;
            
                sum_rt += ps[maxpri_index].rt;
                sum_tat += ps[maxpri_index].tat;
                sum_wt += ps[maxpri_index].wt;

                completed++;
                is_completed[maxpri_index] = true;
            }
        }
    }
    
    for( int i = 0 ;i<n  ;i++)
    {
        total_time = findmax(total_time , ps[i].ct);
    }
    
   utilisation = ( total_time - total_idle_time) / total_time;

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt);
    }
    printf("Average RT : \t%f\nAverage TAT : \t%f\nAverage WT : \t%f\n", sum_rt / n, sum_tat / n, sum_wt / n);
    printf("ThroughPut : %f\n", n / total_time);
    printf("CPU Utilisation : %.2f %%\n ", utilisation * 100);
    return 0;
}
