#include <bits/stdc++.h>
using namespace std;
#define Max 100
int main()
{
    int str[Max][Max];
    int i, j, m, n;
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cin >> str[i][j];
        }

    set<int> freq;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            if (freq.find(str[i][j]) != freq.end())
            {
                cout << "yes" << endl;
                return 0;
            }
            else
            {
                freq.insert(str[i][j]);
            }
        }
    cout << "no" << endl;
    return 0;
}
// O(mn*log(mn))