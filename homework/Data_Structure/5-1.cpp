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
int leaf(Bitree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        if (T->lchild == NULL && T->rchild == NULL)
            return 1;
        return leaf(T->lchild) + leaf(T->rchild);
    }
}
int main()
{
    Bitree T;
    create(T);
    cout << leaf(T) << endl;
    return 0;
}