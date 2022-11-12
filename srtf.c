#include <stdio.h>


void min_bt(int at[] , int bt[], int n , int c , int index )
{
    int min = index;
    for (int i = 0; i < n; i++)
    {
        if(at[i] <= c)
        {
             if (bt[i] > bt[min])
            min = i;
        }
       
    }
    bt[min]--;
     printf("P%d ", min + 1);
    return ;
}

void firstProcess(int at[], int bt[], int n)
{
    int f = 0 ;
    int c = 0;
   for (int j = 0; j  < n; j++){
     for (int i = 0; i  < n; i++)
    {
        if (at[i] == c)
        {

            min_bt(at , bt , n , c  , i ) ;
            c++;
            f++;
            break;
        }
    }
    if(f == 0)
    {
         c++;
           printf("_ ");
    }
  
   }
   
   
    
}

int main()

{

    int n;

    printf("Enter the number of process : ");

    scanf("%d", &n);

    int at[n], bt[n];

    for (int i = 0; i < n; i++)

    {

        scanf("%d%d", &at[i], &bt[i]);
    }

    for (int i = 0; i < n; i++)

    {

        printf("P%d %d %d\n", i + 1, at[i], bt[i]);
    }

   // printf("fist Process is %d\n", );
firstProcess(at, bt, n);

    return 0;
}
