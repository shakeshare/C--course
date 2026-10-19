#include <bits/stdc++.h>
using namespace std;

vector<int> v;

typedef struct Bitnode {
    int data;
    struct Bitnode *lchild;
    struct Bitnode *rchild;
} Bitnode, *Bitree;

// 中序遍历：将节点值依次压入 vector v
void traver(Bitree T) {
    if (T) {
        traver(T->lchild);
        v.push_back(T->data);
        traver(T->rchild);
    }
}

// 判断中序序列是否递增（若递增则是 BST）
bool IsBstree(const vector<int> &v) {
    for (int i = 0; i < (int)v.size() - 1; ++i) {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

// 创建节点
Bitree newNode(int x) {
    Bitree p = new Bitnode;
    p->data = x;
    p->lchild = p->rchild = NULL;
    return p;
}

int main() {
    // 手动构建一棵二叉树
    Bitree T = newNode(10);
    T->lchild = newNode(5);
    T->rchild = newNode(15);
    T->rchild->lchild = newNode(12);
    T->rchild->rchild = newNode(20);

    // 清空 vector 并进行中序遍历
    v.clear();
    traver(T);

    // 输出中序遍历结果
    cout << "中序遍历结果：";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // 判断是否为二叉排序树
    if (IsBstree(v))
        cout << "是二叉排序树" << endl;
    else
        cout << "不是二叉排序树" << endl;

    return 0;
}
