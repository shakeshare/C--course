#include <bits/stdc++.h>
using namespace std;
vector<char> s1;
vector<char> s2;
map<char, int> m;
int main()
{
    string input;
    cin >> input;
    for (char c : input)
    {
        if (isalpha(c))
        {
            s1.push_back(c);
        }
    }
    input.clear();
    cin >> input;
    for (char c : input)
    {
        if (isalpha(c))
        {
            s2.push_back(c);
        }
    }
    // input
    for (char c : s1)
    {
        m[c]++;
    }
    for (char c : s2)
    {
        m[c]++;
    }
    cout << '{';
    bool first = true;
    for (auto &t : m)
    {
        if (!first)
        {
            cout << ',';
        }
        cout << t.first;
        first = false;
    }
    cout << '}' << endl;
    // +
    first = true;
    cout << '{';
    for (auto &t : m)
    {
        if (t.second > 1)
        {
            if (!first)
            {
                cout << ',';
            }
            cout << t.first;
            first = false;
        }
    }
    cout << '}' << endl;
    // jiao
    first = true;
    cout << '{';
    for (auto &t : m)
    {
        char target = t.first;
        if (t.second == 1 && find(s1.begin(), s1.end(), target) != s1.end())
        {
            if (!first)
            {
                cout << ',';
            }
            cout << t.first;
            first = false;
        }
    }
    cout << '}' << endl;
    // -
    first = true;
    cout << '{';
    for (auto &t : m)
    {
        if (t.second == 1)
        {
            if (!first)
            {
                cout << ',';
            }
            cout << t.first;
            first = false;
        }
    }
    cout << '}' << endl;
    // c+
    return 0;
}