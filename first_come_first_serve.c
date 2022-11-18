// First Comes First Serve 
// Non Preemptive 
#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid, at, bt, ct, tat, wt, st;
} ps[100];

int comparatorAT(const void *a, const void *b)
{
    int x = ((struct process *)a)->at;
    int y = ((struct process *)b)->at;
    if (x < y)
        return -1;
    else if (x >= y)
        return 1;
}
int comparatorPID(const void *a, const void *b)
{
    int x = ((struct process *)a)->pid;
    int y = ((struct process *)b)->pid;
    if (x < y)
        return -1;
    else if (x >= y)
        return 1;
}
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
    }

    qsort((void *)ps, n, sizeof(struct process), comparatorAT);

    float sum_tat = 0, sum_ct = 0, sum_wt = 0, total_idle_time = 0, total_time = 0, utilisation = 0;

    for (int i = 0; i < n; i++)
    {
        ps[i].st = (i == 0) ? ps[i].at : findmax(ps[i].at, ps[i - 1].ct);

        ps[i].ct = ps[i].st + ps[i].bt;
        ps[i].tat = ps[i].ct - ps[i].at;
        ps[i].wt = ps[i].tat - ps[i].bt;

        sum_ct += ps[i].ct;
        sum_tat += ps[i].tat;
        sum_wt += ps[i].wt;

        total_idle_time = (i == 0) ? 0 : ps[i].st - ps[i - 1].ct;
    }

    total_time = ps[n - 1].ct;
    utilisation = (total_time - total_idle_time) / total_time;

    qsort((void *)ps, n, sizeof(struct process), comparatorPID);
    printf("After Sort  \n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt);
    }
    printf("Average CT : \t%f\nAverage TAT : \t%f\nAverage WT : \t%f\n", sum_ct / n, sum_tat / n, sum_wt / n);
    printf("ThroughPut : %f\n", n / total_time);
    printf("CPU Utilisation : %.2f %%\n ", utilisation * 100);
    return 0;
}
