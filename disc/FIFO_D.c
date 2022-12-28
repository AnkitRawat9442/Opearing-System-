#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int total_cylinder, n, total_head_movement = 0, head ;
    printf("Enter the total cylinder : ");
    scanf("%d", &total_cylinder);
    printf("Enter the number of cylinder in queue");
    scanf("%d", &n);
    int req_queue[n ];
    for (int i = 0; i < n; i++)
        scanf("%d", &req_queue[i]);
    printf("Enter the position of head : ");
    scanf("%d", &head);
     
    for(int i =0 ;i< n ;i++)
    {
        total_head_movement += abs(head - req_queue[i]);
        head = req_queue[i];
    }

    printf("Total head movement : %d", total_head_movement);

    return 0;
}