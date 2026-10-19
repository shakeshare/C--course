#include <bits/stdc++.h>
using namespace std;
int partition(int r[], int low, int high)
{
    int pivot = r[low];
    while (low < high)
    {
        while (low < high && r[high] >= pivot)
            high--;
        r[low] = r[high];
        while (low < high && r[low] <= pivot)
            low++;
        r[high] = r[low];
    }
    r[low] = pivot;
    return low;
}
int search(int key, int r[], int low, int high)
{
    if (low > high)
        return -1;
    int Index = partition(r, low, high);
    if (r[Index] == key)
        return Index;
    else if (r[Index] > key)
        return search(key, r, low, Index - 1);
    else
        return search(key, r, Index + 1, high);
}
int main()
{
     int n;
     cin >> n;
     int key;
     cin >> key;
     int r[n+1]={0};
     for(int i = 1; i <= n; i++)
     {
         cin >> r[i];
     }
    int low = 1, high = n;
    int result=search(key, r, low, high);
    if(result==-1)
    {
        cout << "Not Find" << endl;
    }
    else 
    {
        cout  << result << ' ' << r[result] << endl;
    }
}