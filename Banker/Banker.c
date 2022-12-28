#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Process
{
    int pid;
    int max[10], allocated[10], need[10];
} PS[50];

int available[10];

bool BankerAlgo(int no_of_process, int no_of_resource, int sequence[])
{
    int work[no_of_resource], k = 0;
    bool finish[no_of_process], proceed = true;
    for (int j = 0; j < no_of_resource; j++)
        work[j] = available[j];
    for (int j = 0; j < no_of_process; j++)
        finish[j] = false;
    while (proceed)
    {
        proceed = false;
        for (int i = 0; i < no_of_process; i++)
        {
            bool flag = true;
            if (finish[i] == false)
            {
                for (int j = 0; j < no_of_resource; j++)
                {
                    if (PS[i].need[j] <= work[j])
                        continue;
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                    continue;

                for (int j = 0; j < no_of_resource; j++)
                    work[j] += PS[i].allocated[j];

                sequence[k++] = i;
                finish[i] = true;
                proceed = true;
            }
        }
    }
   
    if (k == no_of_process)
        return true;

    return false;
}

int main()
{
    int no_of_process, no_of_resource;
    printf("Enetr the Number of the process  : ");
    scanf("%d", &no_of_process);
    printf("Enter the number of resources  : ");
    scanf("%d", &no_of_resource);
    for (int i = 0; i < no_of_process; i++)
    {
        PS[i].pid = i;
        printf("Process P%d\n", i);
        printf("Enter the Max array : ");
        for (int j = 0; j < no_of_resource; j++)
            scanf("%d", &PS[i].max[j]);
        printf("Enter the Allocated  array : ");
        for (int j = 0; j < no_of_resource; j++)
            scanf("%d", &PS[i].allocated[j]);
        for (int j = 0; j < no_of_resource; j++)
            PS[i].need[j] = PS[i].max[j] - PS[i].allocated[j];
    }
    printf("Enter the available array : ");
    for (int j = 0; j < no_of_resource; j++)
        scanf("%d", &available[j]);

    int sequence[no_of_process];

    if (BankerAlgo(no_of_process, no_of_resource, sequence))
    {
        for (int i = 0; i < no_of_process; i++)
        {
            printf("P%d\t", sequence[i]);
        }
    }
    else
    {
        printf("No safe Sequence !!!");
    }

    return 0;
}
