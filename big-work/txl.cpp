#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
typedef struct Friend
{
    string name;
    string id;
}txr;
int choice;
char c;
vector<txr> txl;

void menu()
{
    cout << "-----------------------------------------" << endl;
    cout << "          1. Enter a new record          " << endl;
    cout << "          2. Delete a record             " << endl;
    cout << "          3. List all records            " << endl;
    cout << "          4. Search for a record         " << endl;
    cout << "          5. Save records to file        " << endl;
    cout << "          6. Load records from file      " << endl;
    cout << "          0. Exit                        " << endl;
    cout << "-----------------------------------------" << endl;
    return ;
}
void enter()
{
    if(txl.size() == 0)
    {
        cout << "没有数据" << endl;
    }
    while(true)
  {   cout << "按Y继续输入,按N退出" << endl;
    cin >> c;
    if(c == 'Y' || c == 'y')
    {
        txr t;
        cout << "请输入姓名" << endl;
        cin >> t.name;
        cout << "请输入ID" << endl;
        cin >> t.id;
        txl.push_back(t);
        cout << "输入成功" << endl;
    }
    else if(c == 'N' || c == 'n')
    {
        cout << "退出成功" << endl;
        break;
    }
    else
    {
        cout << "输入错误" << endl;
    }}
    return;
}
void del()
{
  while(true) {
      cout << "输入要删除的联系人的姓名" << endl;
        string name;
        cin >> name;
        if(cin.get() == '\n')
       {auto p = find_if(txl.begin(), txl.end(), [&](const txr& t) { return t.name == name; });
        if (p != txl.end())
        {
            cout << "查询到该联系人,按Enter键删除" << endl;
            if(cin.get() == '\n')
            {
                 txl.erase(p);
                cout << "删除成功" << endl;
            }
            else
            {
                cout << "输入错误" << endl;
            }
           
        }
        else
        {
            cout << "没有找到该联系人" << endl;
        }}
        cout << "按Y继续删除,按N退出" << endl;
        cin >> c;
        if(c == 'N' || c == 'n')
        {
            cout << "退出成功" << endl;
            break;
        }
        else if(c == 'Y' || c == 'y')
        {
            continue;
        }
        else
        {
            cout << "输入错误" << endl;
        }
        return;
}}
void listrecord()
{
    if (txl.empty()) {
        cout << "没有联系人记录" << endl;
        return;
    }
    cout << "联系人列表：" << endl;
    for (const auto& t : txl) {
        cout << "姓名: " << t.name << ", ID: " << t.id << endl;
    }
    return;
}
void search()
{
    string name;
     cout << "输入要查询的联系人的姓名后按Enter键查询" << endl;
        if(cin.get() == '\n')
       {cin >> name;
        auto p = find_if(txl.begin(), txl.end(), [&](const txr& t) { return t.name == name; });
        if (p != txl.end())
        {
            cout << "姓名: " << p->name << ", ID: " << p->id << endl;
        }
        else
        {
            cout << "没有找到该联系人" << endl;
        }}
        return  ;
}
void save()
{
     cout << "按Enter键保存" << endl;
        cin.ignore(); 
        if(cin.get() == '\n')
       { ofstream file("Saving file.txt");
        if (file.is_open()) {
            for (const auto& t : txl) {
                file << "姓名: " << t.name << ", ID: " << t.id << endl;
            }
            file.close();
            cout << "保存成功" << endl;
        } else {
            cout << "无法打开文件进行保存" << endl;
        }}
        return ;
}
void load()
{       cout << "按Enter键加载" << endl;
        cin.ignore(); 
        if(cin.get() == '\n')
       { ifstream file("Saving file.txt");
         if(file.is_open())
              {
                txl.clear();
                string line;
                while(getline(file, line))
                {
                    if (line.empty()) continue;
                    txr temp;
                    temp.name = line.substr(8, line.find(",") - 8);
                    temp.id = line.substr(line.find(",") + 6);
                    txl.push_back(temp);
                }
                file.close();
                cout << "成功打开文件进行加载" << endl;
              }
            else
            {
                cout << "无法打开文件进行加载" << endl;
            }}
            return ;
}
int main()
{
    while(true)
    {
        menu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                enter();
                break;
            case 2:
                del();
                break;
            case 3:
                listrecord();
                break;
            case 4:
                search();
                break;
            case 5:
                save();
                break;
            case 6:
                load();
                break;
            case 0:
                cout << "退出成功" << endl;
                exit(0);
            default:
                cout << "无效操作,请重新输入" << endl;
        }
        
    }
    return 0;
}
