#include <bits/stdc++.h>
using namespace std;
bool check( vector<int>& arr,int n)
{
     int i;
   for(i=0;i<arr.size();i++)
  {   if (n == arr[i] || abs(n-arr[i]) == abs(i - static_cast<int>(arr.size()+1)))
          return false;
    }
    return true;
}
int nextqueen( vector<int>&arr,int n)
{
  int i,ct=0;
  for(i = 0; i < n; i++)
  {
    if (check(arr,i))
    {
      arr.push_back(i);
      ct += nextqueen(arr,n);
      arr.pop_back();
    }
  }
  if(arr.size() == n)
  {
     ct++;   
  }
  return ct;
}
int main()
{
    int n,c;
    vector <int> arr;
      cin >> n >> c;
      arr.push_back(c);
      cout << nextqueen(arr,n) << endl;
      return 0;
}
