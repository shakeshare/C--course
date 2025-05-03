#include <stdio.h>
#include <stdlib.h>
double res[100000]={0};
int main()
{
   int floor[104];
   int n;
   int i;
   int fln=0;
   double sum=0;
   int ct=0;

   while(scanf("%d", &n) )
   {
         if(n == 0)
              break;
       for(i = 0; i < n; i++)
       {
           scanf("%d", &floor[i]);
       }
        sum = 0;
       for(i = 0; i < n; i++)
       {
           sum += abs(floor[i]-fln)*2.9;
              fln = floor[i];
       }
       res[ct] = sum;
       ct++;
   }
    for(i = 0; i < ct; i++)
    {
        printf("%.1f\n", res[i]);
    }
    return 0;   
}
