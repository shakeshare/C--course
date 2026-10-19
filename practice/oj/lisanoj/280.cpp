#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n,i,j,k;
   bool flag=true;
   cin >> n;
    vector<vector<int>> arr(n,vector<int>(n));
    for( i = 0; i < n; i++)
    {
        for( j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          for(k=0;k<n;k++)
          {
              if(arr[i][j]&&arr[j][k]&&!arr[i][k])
              {
                  flag = false;
                  break;
              }
          }
      }
    }
   
    if(flag)
    {
      cout << "The matrix is transitive." << endl;  
      return 0; 
    }
    else
    {
        cout << "The matrix is not transitive." << endl;   
        return 0;   
    }
}