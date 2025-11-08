#include <bits/stdc++.h>
using namespace std;
typedef struct Bitnode
{
    char data;
    struct Bitnode *lchild, *rchild;
} Bitnode, *Bitree;
void create(Bitree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new Bitnode;
        T->data = ch;
        create(T->lchild);
        create(T->rchild);
    }
}
void swap(Bitree &T)
{
    if (T == NULL)
        return;
    Bitnode *temp;
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    swap(T->lchild);
    swap(T->rchild);
}
void print(Bitree T)
{
    if (T == NULL)
        return;
    print(T->lchild);
    cout << T->data;
    print(T->rchild);
}
int main()
{
    Bitree T;
    create(T);
    swap(T);
    print(T);
    return 0;
}