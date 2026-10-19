#include <bits/stdc++.h>
using namespace std;
int arr[104];
int main()
{
    int n;
    cin >> n;
    bool ismin = true;
    bool ismax = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n / 2; i++)
    {
        if (2 * i <= n)
        {
            if (arr[i] > arr[2 * i])
                ismin = false;
            if (arr[i] < arr[2 * i])
                ismax = false;
        }
        if (2 * i + 1 <= n)
        {
            if (arr[i] > arr[2 * i + 1])
                ismin = false;
            if (arr[i] < arr[2 * i + 1])
                ismax = false;
        }
        if (!ismin && !ismax)
            break;
    }
    if (ismin)
    {
        cout << "Min heap" << endl;
    }
    else if (ismax)
    {
        cout << "Max heap" << endl;
    }
    else
    {
        cout << "Not heap" << endl;
    }
    return 0;
}