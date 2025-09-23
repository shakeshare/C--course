#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    bool flag1 = true;
    bool flag2 = true;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i][i] != 1)
        {
            flag1 = false;
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i][i] != 0)
        {
            flag2 = false;
            break;
        }
    }
    if (flag1)
    {
        cout << "The matrix is reflexive." << endl;
        return 0;
    }
    if (flag2)
    {
        cout << "The matrix is irreflexive." << endl;
        return 0;
    }
    else
    {
        cout << "The matrix is not irreflexive or reflexive." << endl;
        return 0;
    }
}