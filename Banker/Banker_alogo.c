#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct process
{
    int pid;
    int max[10], allocated[10], need[10];
} ps[100];

int available[10];

void inputValues(int no_process, int no_res)
{
    for (int i = 0; i < no_process; i++)
    {
        ps[i].pid = i;
        printf("enter the max vales :  ");
        for (int j = 0; j < no_res; j++)
        {
            scanf("%d", &ps[i].max[j]);
        }
        printf("enter the allocated value : ");
        for (int j = 0; j < no_res; j++)
        {
            scanf("%d", &ps[i].allocated[j]);
            ps[i].need[j] = ps[i].max[j] - ps[i].allocated[j];
        }
    }
    printf("Enter the available values  : ");
    for (int j = 0; j < no_res; j++)
    {
        scanf("%d", &available[j]);
    }
}

void printValues(int no_process, int no_res)
{
    printf("Ps\tAllo\tMax\tNeed\tAvai\n");
    for (int i = 0; i < no_process; i++)
    {
        printf("P%d\t", ps[i].pid);
        for (int j = 0; j < no_res; j++)
        {
            printf("%d ", ps[i].allocated[j]);
        }
        printf("\t");
        for (int j = 0; j < no_res; j++)
        {
            printf("%d ", ps[i].max[j]);
        }
        printf("\t");
        for (int j = 0; j < no_res; j++)
        {
            printf("%d ", ps[i].need[j]);
        }
        printf("\t");
        for (int j = 0; j < no_res; j++)
        {
            if (i == 0)
                printf("%d ", available[j]);
        }
        printf("\n");
    }
}

void solution(int no_process, int no_res)
{
    int completed = 0;
    bool iscompleted[100] = {false};
    bool is_first_process = true;
    int index = -1, i;
    while (completed != no_process)
    {
        i = is_first_process == true ? 0 : (index + 1) % no_process;

        for (i; i < no_process; i++)
        {
            int temp = 0;
            if (iscompleted[i] == false)
            {
                for (int j = 0; j < no_res; j++)
                {
                    if (ps[i].need[j] > available[j])
                    {
                        temp++;
                        break;
                    }
                }
                if (temp == 0)
                {
                    index = i;
                    break;
                }
            }
        }
        //  printf("index : %d", index);
        for (int i = 0; i < no_res; i++)
        {
            available[i] += ps[index].allocated[i];
        }
        is_first_process == true ? printf("P%d ", index) : printf("-> P%d ", index);
        completed++;
        iscompleted[index] = true;
        is_first_process = false;
    }
}

int main()
{
    int n, res;
    printf("Enter the no process and no of resource  : ");
    scanf("%d%d", &n, &res);
    inputValues(n, res);
    printValues(n, res);

    solution(n, res);

    return 0;
}
