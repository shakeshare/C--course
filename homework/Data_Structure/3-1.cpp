#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int top[2], bot[2];
    char *V;
    int m;
} DblStack;
char InitDblStack(DblStack &a, int m)
{
    a.V = new char[m];
    a.bot[0] = -1;
    a.top[0] = -1;
    a.bot[1] = m;
    a.top[1] = m;
    return 1;
}
char Enter(DblStack &a, int i, char x)
{
    if (a.top[1] - a.top[0] == 1)
    {
        return 0;
    }
    if (i == 0)
    {
        a.top[0]++;
        a.V[a.top[0]] = x;
    }
    if (i == 1)
    {
        a.top[1]--;
        a.V[a.top[1]] = x;
    }
    return 1;
}
char Del(DblStack &a, int i, char x)
{
    if (a.top[i] == a.bot[i])
    {
        return 0;
    }
    if (i == 0)
    {
        x = a.V[a.top[0]];
        a.top[0]--;
    }
    if (i == 1)
    {
        x = a.V[a.top[1]];
        a.top[1]++;
    }
    return 1;
}
bool IsEmpty(DblStack &a, int i, int m)
{
    if (i == 0)
    {
        if (a.top[0] == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (i == 1)
    {
        if (a.top[1] == m)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
bool IsMax(DblStack &a, int i, int m)
{
    if (a.top[0] + 1 == a.top[1])
        return 1;
    else
        return 0;
}