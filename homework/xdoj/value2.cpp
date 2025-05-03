#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;
#define MAXLEN 100+4
char str[10][MAXLEN];
int priority(char c)
{
   if(c=='+'||c=='-')
        return 1;
    else if(c=='*')
        return 2;
    else if(c=='(')
        return 0;
return -1;  
}
long long jx(char *s)
{
    stack<char> s1;
    stack<long long int> s2;
    int i=0;
    char token1;
    long long num1,num2;
    int leng;
    leng=strlen(s);
    for(i=0;i<leng;i++)
    {
        if (isdigit(s[i])) {
            long long num = 0;
            while (i < leng && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            s2.push(num);
            i--; 
            continue; }
   
        if(s[i]=='(')
        {
            s1.push(s[i]);
            continue;
        }
   
        if(s1.empty()&&(!(isdigit(s[i]))))
            {
                s1.push(s[i]);
                continue;
            }

        if(!s1.empty()&&(s[i]!=')')&&priority(s[i])<=priority(s1.top()))
                {
                    token1=s1.top();
                    s1.pop();
                    num2=s2.top();
                    s2.pop();
                    num1=s2.top();
                    s2.pop();
                  if(token1=='+')
                        s2.push(num1+num2);
                    else if(token1=='-')
                        s2.push(num1-num2);
                    else if(token1=='*')
                        s2.push(num1*num2);
                    
                }
        
        if(s[i]==')')
      {    while(s1.top()!='(')
            {
                token1=s1.top();
                s1.pop();
                num2=s2.top();
                s2.pop();
                num1=s2.top();
                s2.pop();
                if(token1=='+')
                    s2.push(num1+num2);
                else if(token1=='-')
                    s2.push(num1-num2);
                else if(token1=='*')
                    s2.push(num1*num2);
                else if(token1=='/')
                    s2.push(num1/num2);
            }
            s1.pop();
            continue;}
            s1.push(s[i]);
        }

    // 处理栈中剩余的运算符
while(!s1.empty())
    {
        token1=s1.top();
        s1.pop();
        num2=s2.top();
        s2.pop();
        num1=s2.top();
        s2.pop();
        if(token1=='+')
            s2.push(num1+num2);
        else if(token1=='-')
            s2.push(num1-num2);
        else if(token1=='*')
            s2.push(num1*num2);
        else if(token1=='/')
            s2.push(num1/num2);
    }
    return s2.top();
}
    




int main()
{
    
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str[i]);
       
    }
    for(i=0;i<n;i++)
    {
    printf("%lld\n",jx(str[i]));

    }
    return 0;
}