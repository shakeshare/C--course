#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num, key;
    string s;
    cin >> num;
    while (num--)
    {
        stack<char> s1;
        key = 1;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                s1.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (s1.empty())
                {
                    key = 0;
                    break;
                }
                if (((s[i] == ')' && s1.top() == '(') ||
                     (s[i] == ']' && s1.top() == '[') ||
                     (s[i] == '}' && s1.top() == '{')))
                    s1.pop();
                else
                {
                    key = 0;
                    break;
                }
            }
           
        }
        
      if(!(s1.empty())) 
           { key = 0;}
        if (key == 1)
            cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}