#include <bits/stdc++.h>
using namespace std;
vector<string> processWord(const string& word) {
    vector<string> parts;
    int len = word.length();

    if (len >= 3 && word.substr(len - 3) == "'re") {
        string part1 = word.substr(0, len - 3);
        if (!part1.empty()) {
            parts.push_back(part1);
        }
        parts.push_back("are");
    } 
    else if (len >= 2){
        string part2 = word.substr(len - 2);
        if (part2 == "'s") {
            string part3 = word.substr(0, len - 2);
            if (!part3.empty()) {
                parts.push_back(part3);
            }
            parts.push_back("is");
        } else if (part2 == "'m") 
        {

            string part4 = word.substr(0, len - 2);
            if (!part4.empty()) {
                parts.push_back(part4);
            }
            parts.push_back("am");
        }
    
   else {
            parts.push_back(word);
        }}
    else
    {
        parts.push_back(word);
    }
    return parts;
} 
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
    stringstream ss(text);
    map<string, int> wordCount;
    string word;
    while (ss >> word) {
        vector<string> parts = processWord(word);
        for (const auto& part : parts) {
            wordCount[part]++;
        }
    }
    cout << wordCount.size() << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << " " << pair.second << endl;
    } //map自动按字典序排序输出

    return 0;
}


