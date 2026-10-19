#include <bits/stdc++.h>
using namespace std;

struct Bstnode {
    int data;
    int count;
    Bstnode *llink;
    Bstnode *rlink;
};

int main() {
    cout << "开始无限分配内存（每次 new 一个 Bstnode，不保存指针）..." << endl;
    cout << "打开任务管理器观察内存增长。" << endl;
    cout << "(按 Ctrl + C 结束程序)\n" << endl;

    while (true) {
        new Bstnode;  // 🚨 不保存返回值 → 永久丢失 → 内存泄漏
    }

    return 0;
}
