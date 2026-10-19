#include <stdio.h>
int main()
{
    int H;
    scanf("%d", &H);
    int h[11]={0};
    int i;
    for(i=0;i<=10;i++)
       h[i]=(H>>(i))&1;
    int s1,s2,s3,s4;
    s1=h[0]^h[2]^h[4]^h[6]^+h[8]^h[10];
    s2=h[1]^h[2]^h[5]^h[6]^h[9]^h[10];
    s3=h[3]^h[4]^h[5]^h[6];
    s4=h[7]^h[8]^h[9]^h[10];
    int s=s1+s2*2+s3*4+s4*8;
    if(s!=0)
   {     h[s-1] = !h[s-1];}
    for(i=10;i>=0;i--)
    {    if(i!=0&&i!=1&&i!=3&&i!=7)
          printf("%d",h[i]);}
    return 0;   
   }