#include<stdio.h>
#include<math.h>
#define e 0.001
#define f(x) pow(x,3)-4*x+1
#define df(x) 3*x*x-4
int main()
{
    float x0,x1,f0,f1,fdx;
    int i;
     printf("enter the value of first point\n");
    scanf("%f\n",&x0);
    do{
    
   
    f0=f(x0);
    df0=df(x0);
    x1=x0-(f0/df0);
    f1=f(x1);
    x0=x1;
    i++;
    printf("root of equation%f\n",x1);
    printf(" total iteration%d\n",i);
    printf("value of eqation%f\n",f1);
    }while(fabs(f1)>e);
    
    return 0;
    
}