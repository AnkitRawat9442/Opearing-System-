#include <stdio.h>
#include <math.h>


int closestcylinder (int req[] , int n , int head , int v[]  )
{
    int min = 32000 , index = -1;
     for(int i = 0;i< n ;i++)
    {
         if( v[i] == 0 &&  min >  abs(head - req[i]))
            {
                min = abs(head - req[i]);
                index = i;
            }
    }
    return index ;
}

int main()
{
    int total_cylinder, n, total_head_movement = 0, head ;
    printf("Enter the total cylinder : ");
    scanf("%d", &total_cylinder);
    printf("Enter the number of cylinder in queue");
    scanf("%d", &n);
    int req_queue[n ] , visited[n] ;

    for (int i = 0; i < n; i++)
    {  
        scanf("%d", &req_queue[i]);
        visited[i] = 0;

    }
        
    printf("Enter the position of head : ");
    scanf("%d", &head);
     int index = 0 ;
    for(int i =0 ;i< n ;i++)
    {
        index = closestcylinder(req_queue , n, head , visited);
        total_head_movement += abs(head - req_queue[index]);
        head = req_queue[index];
        visited[index] = 1;
    }

    printf("Total head movement : %d", total_head_movement);

    return 0;
}