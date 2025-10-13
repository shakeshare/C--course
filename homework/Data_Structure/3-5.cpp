// (1) 1 (2) 0 (3) 1 (4) 1
#include <bits/stdc++.h>
using namespace std;
bool isvalid(char str[])
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'I')
            count++;
        else if (str[i] == 'O')
            count--;
        if (count < 0)
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    char str[10];
    cin >> str;
    if (isvalid(str))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}