#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 512 //假设图像最大为512*512
unsigned char gimage[MAX][MAX]={0};
unsigned char mimage[MAX][MAX]={0};
void read(const char* path,int n)
{    
     FILE *fp;
     int i;
    fp=fopen(path,"rb");
    if(fp==NULL)
    {
        printf("error\n");
        exit(1);
    }
        fread(gimage,sizeof(unsigned char),n*n,fp);

    fclose(fp);
}
void write(const char* path,int n)
{
     FILE *fp;
     int i;
    fp=fopen(path,"wb");
    if(fp==NULL)
    {   
        printf("error\n");
        exit(1);
    }
    
    
    fwrite(mimage,sizeof(unsigned char),n*n,fp);
    
    fclose(fp);
}
void convert(unsigned char gimage[MAX][MAX],unsigned char mimage [MAX][MAX],int r,double t,int n)
{
    int i,j;
    int x,y;
    double count=0;
    double sum=0;
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
  {  
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
          
            if(abs(x-i)<=r && abs(y-j)<=r)
            {
                sum=gimage[x][y]+sum;
                count++;

            }
        }
    }
    sum=sum/count;
if(sum>t)
    {
        mimage[i][j]=255;
    }
    else
    {
        mimage[i][j]=0;
    }
    sum=0;
    count=0;
  }
}
    return ;
}
  
int main(int argc,char *argv[])
{
   const char *gray,*mono;
   int r;
   double t;
   int n;
   scanf ("%d",&n);
    gray=argv[1];
    mono=argv[2];
    r=atoi(argv[3]+3);
    t=atof(argv[4]+3);
    read(gray,n);
    convert(gimage,mimage,r,t,n);
    write(mono,n);
    return 0;
}   