#include <iostream>
#include <string>
using namespace std;

int nextval[100];

void getnextval(string t, int nextval[])
{
    int i = 0;
    int j = -1;
    nextval[0] = -1;
    int len = t.length();

    while (i < len)
        if (j == -1 || t[i] == t[j])
        {
            i++;
            j++;
            if (i < len && t[i] != t[j])
            {
                nextval[i] = j;
            }
            else
            {
                nextval[i] = nextval[j];
            }
        }
        else
        {
            j = nextval[j];
        }
}

int index(string s, string t, int pos)
{
    int i = pos;
    int j = 0;
    int s_len = s.length();
    int t_len = t.length();

    while (i < s_len && j < t_len)
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j];
        }
    }

    if (j == t_len)
    {
        return i - t_len;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    getnextval(t, nextval);
    int pos = index(s, t, 0);

    if (pos != -1)
    {
        cout << pos + 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}