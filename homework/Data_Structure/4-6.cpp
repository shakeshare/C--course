#include <bits/stdc++.h>
using namespace std;
#define Max 100
int main()
{
    int s1[Max], s2[Max];
    int i, m, left, right;
    cin >> m;
    left = 0;
    right = m - 1;
    for (i = 0; i < m; i++)
    {
        cin >> s1[i];
    }
    for (i = 0; i < m; i++)
    {
        if (s1[i] >= 0)
        {
            s2[left] = s1[i];
            left++;
        }
        else
        {
            s2[right] = s1[i];
            right--;
        }
    }
    for (i = 0; i < m; i++)
    {
        cout << s2[i] << " ";
    }
    return 0;
}