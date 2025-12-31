#include <bits/stdc++.h>
using namespace std;
int H(int n, int p)
{
    return n % p;
}
int exist(vector<int> &v, int x, int p)
{
    int m = v.size();
    int pos = H(x, p);
    int start = pos;

    while (v[pos] != -1)
    {
        if (v[pos] == x)
            return pos;
        pos = (pos + 1) % m;
        if (pos == start)
            break;
    }
    return -1;
}
int main()
{
    int m, p, x;
    int used=0;
    cin >> m >> p;
    vector<int> v(m, -1);
    while (cin >> x && x != -1)
    {
        int pos = H(x, p);
        int key = exist(v, x, p);
        if (key != -1)
        {
            cout << key << endl;
            continue;
        }
        if (v[pos] == -1)
        {
            v[pos] = x;
            used++;
            cout << pos << endl;
        }
        else
        {
            if (used == m - 1)
            {
                cout << "Table full" << endl;
                break;
            }
            while (v[pos] != -1)
            {
                pos = (pos + 1) % m;
            }
            v[pos] = x;
            used++;
            cout << pos << endl;
        }
    }
    return 0;
}
