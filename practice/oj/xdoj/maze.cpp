#include <bits/stdc++.h>
using namespace std;
#define Maxleng 22
int maze[Maxleng][Maxleng];
int mazedist[Maxleng][Maxleng];
typedef struct position
{
    int x;
    int y;
}pos;
pos location[Maxleng*Maxleng];
queue<pos> q,h;


int main (){
     memset(mazedist,-1000,sizeof(mazedist));
     pos start,end,temp;
     int m;
     int count=0;
     scanf("%d %d %d %d %d", &m, &start.x, &start.y, &end.x, &end.y);
     int i,j;
     for(i=1;i<=m;i++)
   {       for(j=1;j<=m;j++)
              scanf("%d", &maze[i][j]);
   }
    q.push(start);  
    mazedist[start.x][start.y]=0;
    while(q.front().x!=end.x||q.front().y!=end.y)
         {    
             
               if(maze[(q.front().x)+1][q.front().y]!=1&&(q.front().x)+1<=m)
                  {  mazedist[(q.front().x)+1][q.front().y] = mazedist[q.front().x][q.front().y]+1;
                    temp.x=(q.front().x)+1;
                    temp.y=q.front().y;
                     q.push(temp);}

               if(maze[q.front().x][(q.front().y)+1]!=1&&(q.front().y)+1<=m)
                     {     mazedist[q.front().x][(q.front().y)+1] = mazedist[q.front().x][q.front().y]+1;
                               temp.x=q.front().x;
                               temp.y=(q.front().y)+1;
                               q.push(temp);}
               if(maze[(q.front().x)-1][q.front().y]!=1&&(q.front().x)-1>0)
                               {       mazedist[(q.front().x)-1][q.front().y] = mazedist[q.front().x][q.front().y]+1;
                                           temp.x=(q.front().x)-1;
                                           temp.y=q.front().y;
                                           q.push(temp);}
               if(maze[q.front().x][(q.front().y)-1]!=1&&(q.front().y)-1>0)
              {     mazedist[q.front().x][(q.front().y)-1] = mazedist[q.front().x][q.front().y]+1;
                        temp.x=q.front().x;
                        temp.y=(q.front().y)-1;
                        q.push(temp);}
                 maze[q.front().x][q.front().y] = 1;
                 q.pop();
                
             }   
    printf("%d\n", mazedist[end.x][end.y]);
    // part1
    h.push(end);
    location[0].x=end.x;
    location[0].y=end.y;
    while(h.front().x!=start.x||h.front().y!=start.y)
  {        count++;
     if(((mazedist[(h.front().x)-1][h.front().y]==mazedist[h.front().x][h.front().y]-1)&&((h.front().x)-1>0)))
                   {              location[count].x=(h.front().x)-1;
                                  location[count].y=h.front().y;
                             temp.x=(h.front().x)-1;
                             temp.y=h.front().y;
                             h.push(temp);
                             h.pop();
                             continue;}
 
     if(((mazedist[h.front().x][(h.front().y)-1]==mazedist[h.front().x][h.front().y]-1)&&((h.front().y)-1>0)))
                             {               location[count].x=h.front().x;
                                             location[count].y=(h.front().y)-1; 
                                       temp.x=h.front().x;
                                       temp.y=(h.front().y)-1;
                                       h.push(temp);
                                       h.pop();
                                    continue;}
     if(((mazedist[(h.front().x)+1][h.front().y]==mazedist[h.front().x][h.front().y]-1))&&((h.front().x)+1<=m))
                   {          location[count].x=(h.front().x)+1;
                              location[count].y=h.front().y;
                        temp.x=(h.front().x)+1;
                        temp.y=h.front().y;
                        h.push(temp);
                        h.pop();
                        continue;}
     if(((mazedist[h.front().x][(h.front().y)+1]==mazedist[h.front().x][h.front().y]-1)&&((h.front().y)+1<=m)))
                        {              location[count].x=h.front().x;
                                       location[count].y=(h.front().y)+1;
                                  temp.x=h.front().x;
                                  temp.y=(h.front().y)+1;
                                  h.push(temp);
                                  h.pop();
                                  continue;}
  }
   printf("(%d,%d)", start.x, start.y);
      while(count)
      {
           count--;
         printf("(%d,%d)", location[count].x, location[count].y);

      }
        printf("\n");
      // pant2
      return 0;
}
        
        
        
        
       