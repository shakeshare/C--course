#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    list<int> L={1,2,3,4,5};
    L.push_front(0);
    cin >> a >> b;
    c=max(a,b);
    cout << c << endl;
    return 0;
}