#include <bits/stdc++.h>
using namespace std;


string add(const string &a, const string &b) {
    string res;
    string reva=a, revb=b;
    reverse(reva.begin(), reva.end());
    reverse(revb.begin(), revb.end());
    int rea = 0, i = reva.size()-1, j = revb.size()-1 ;
    while (i >= 0 || j >= 0 || rea) {
        if (i >= 0)
        rea += a[i--] - '0';
        if (j >= 0) 
        rea += b[j--] - '0';
        res.push_back(rea % 10 + '0');
        rea /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    string a,b;
    cin >> a >>b;
    cout << add(a,b) << endl;
    return 0;
}
