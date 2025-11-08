#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    map<char, int> freq;
    getline(cin, s);
    for (char c : s)
    {
        if (isdigit(c) || isalpha(c))
        {
            freq[c]++;
        }
    }
    ofstream outfile("output.txt");
    if (!outfile.is_open())
    {
        cerr << "ERROR" << endl;
        return -1;
    }
    for (auto &t : freq)
    {
        outfile << t.first << "的频度:" << t.second << endl;
    }
    outfile.close();
    return 0;
}