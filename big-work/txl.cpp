#include <bits/stdc++.h>
using namespace std;
int choice;
char c;
void menu()
{
    cout << "1. Enter a new record" << endl;
    cout << "2. Delete a record" << endl;
    cout << "3. List all records" << endl;
    cout << "4. Search for a record" << endl;
    cout << "5. Save records to file" << endl;
    cout << "6. Load records from file" << endl;
    cout << "0. Exit" << endl;
}
void enter()
{

}
void del()
{

}
void listrecord()
{

}
void search()
{

}
void save()
{

}
void load()
{

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
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << "按Y继续,按N退出" << endl;
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

    }
    return 0;
}
