#include <bits/stdc++.h>
using namespace std;
vector<int> s1, s2;
vector<vector<int>> permutations;
int main()
{
    int m, n, i = 0;
    int temp;
    bool first = true;
    cin >> m >> n;
    for (i = 0; i < m; i++)
    {
        cin >> temp;
        s1.push_back(temp);
    }
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        s2.push_back(temp);
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    vector<int> subset(s2.begin(), s2.begin() + m);
    permutations.push_back(subset);
    while (next_permutation(s2.begin(), s2.end()))
    {
        vector<int> subset(s2.begin(), s2.begin() + m);
        permutations.push_back(subset);
    }
    sort(permutations.begin(), permutations.end());
    permutations.erase(unique(permutations.begin(), permutations.end()), permutations.end());
    for (auto &p : permutations)
    {
        cout << '{';
        first = true;
        for (i = 0; i < m; i++)
        {
            if (!first)
            {
                cout << ',';
            }
            cout << '<' << s1[i] << ',' << p[i] << '>';
            first = false;
        }
        cout << '}' << endl;
    }
    return 0;
}
