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
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (arr[i][j] != arr[j][i])
            {
                flag1 = false;
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (arr[i][j] + arr[j][i] == 2)
            {
                flag2 = false;
                break;
            }
        }
    }

    if (flag1 && !flag2)
    {
        cout << "The matrix is symmetric." << endl;
        return 0;
    }
    if (flag2 && !flag1)
    {
        cout << "The matrix is antisymmetric." << endl;
        return 0;
    }
    if (flag1 && flag2)
    {
        cout << "The matrix is antisymmetric and symmetric." << endl;
        return 0;
    }
    else
    {
        cout << "The matrix is not antisymmetric or symmetric." << endl;
        return 0;
    }
}