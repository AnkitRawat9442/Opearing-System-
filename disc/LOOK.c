#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comparator(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y)
        return -1;
    else if (x >= y)
        return 1;
}

int main()
{
    int total_cylinder, n, total_head_movement = 0, head, direction;
    printf("Enter the total cylinder : ");
    scanf("%d", &total_cylinder);
    printf("Enter the number of cylinder in queue");
    scanf("%d", &n);
    int req_queue[n + 1];
    for (int i = 0; i < n; i++)
        scanf("%d", &req_queue[i]);
    printf("Enter the position of head : ");
    scanf("%d", &head);
    printf("Enter the direction (1 if right else 0) : ");
    scanf("%d", &direction);

    req_queue[n] = head;
    qsort((void *)req_queue, n + 1, sizeof(int), comparator);

    int index;
    n = n + 1;
    for (int i = 0; i < n; i++)
    {
        if (req_queue[i] == head)
        {
            index = i;
            break;
        }
    }

    if (direction == 1)
    {
        printf("Seek Sequence : ");
        for (int i = index; i < n; i++)
        {
            total_head_movement += abs(head - req_queue[i]);
            printf("%d\t", req_queue[i]);
            head = req_queue[i];
        }
        for (int i = index - 1; i >= 0; i--)
        {
            total_head_movement += abs(head - req_queue[i]);
            printf("%d\t", req_queue[i]);
            head = req_queue[i];
        }
    }
    else if (direction == 0)
    {
        printf("Seek Sequence : ");
        for (int i = index; i >= 0; i--)
        {
            total_head_movement += abs(head - req_queue[i]);
            printf("%d\t", req_queue[i]);
            head = req_queue[i];
        }
        for (int i = index + 1; i < n; i++)
        {
            total_head_movement += abs(head - req_queue[i]);
            printf("%d\t", req_queue[i]);
            head = req_queue[i];
        }
    }

    printf("\nToatal head movement : %d", total_head_movement);
    return 0;
}
