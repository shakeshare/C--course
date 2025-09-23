#include <bits/stdc++.h>
using namespace std;
typedef struct zuyuan
{
    int x;
    int y;
} zu;
vector<zu> zbl;
int main()
{
    string s1;
    zu temp;
    bool key = false;
    bool first = true;
    cin >> s1;
    for (auto &c : s1)
    {
        if (isdigit(c))
        {
            if (!key)
            {
                temp.x = c - '0';
            }
            if (key)
            {
                temp.y = c - '0';
                zbl.push_back(temp);
            }
            key = !key;
        }
    }
    sort(zbl.begin(), zbl.end(), [](zu &a, zu &b)
         { return a.y < b.y; });
    for (const auto &t : zbl)
    {
        if (!first)
        {
            cout << ',';
        }
        cout << '(' << t.y << ',' << t.x << ')';
        first = false;
    } // vector  结构体默认按插入方式遍历
    return 0;
}