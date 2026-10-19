#include <bits/stdc++.h>
using namespace std;
int main()
{
    string text;
    string fg=",.?!\t\n\r";
    getline(cin, text,'#');
    for(auto& c : text) {
        if (fg.find(c)!= string ::npos) {
            c = ' ';
        }
        c = tolower(c); 
    }
    cout << text << endl;
    stringstream ss(text);
    string word;
    int ct=0;
    while (ss >> word) {
        ct++;

}
        cout << ct << endl;
    
    return 0;
}
