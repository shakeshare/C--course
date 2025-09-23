#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ct = 0;
    cin >> n;
    if (n >= 10 || n < 2)
    {
        return 0;
    }
    string s;
    int i;
    for (i = 1; i <= n; i++)
    {
        s += '0' + i;
    }

    for (ct = 0; ct < n; ct++)
    {
        cout << s[ct] << ' ';
    }
    cout << endl;
    while (next_permutation(s.begin(), s.end()))
    {
        for (ct = 0; ct < n; ct++)
        {
            cout << s[ct] << ' ';
        }
        cout << endl;
    }
    return 0;
}