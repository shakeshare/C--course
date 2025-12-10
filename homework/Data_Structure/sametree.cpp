#include <bits/stdc++.h>
using namespace std;
typedef struct BstNode
{
    char data;
    struct BstNode *lchild, *rchild;
} BsTNode, *BsTree;
void Insert(BsTree &T, char e)
{
    if (!T)
    {
        BsTree s = new BstNode;
        s->data = e;
        s->lchild = s->rchild = NULL;
        T = s;
        return;
    }
    if (e < T->data)
    {
        Insert(T->lchild, e);
    }
    else
    {
        Insert(T->rchild, e);
    }
}
bool Isthesame(BsTree T1, BsTree T2)
{
    if (!T1 && !T2)
        return true;
    if ((!T1 && T2) || (T1 && !T2))
        return false;
    if (T1->data != T2->data)
        return false;
    return Isthesame(T1->lchild, T2->lchild) && Isthesame(T1->rchild, T2->rchild);
}
void FreeTree(BsTree T)
{
    if (!T)
        return;
    FreeTree(T->lchild);
    FreeTree(T->rchild);
    delete T;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            return 0;
        }
        string orn;
        BsTree T = NULL;
        if (cin >> orn)
        {
            for (char ch : orn)
            {
                Insert(T, ch);
            }
        }
        string m;
        for (int i = 0; i<n; i++)
        {

            cin >> m;
            BsTree p = NULL;
            for (char ch : m)
            {
                Insert(p, ch);
            }
            if (Isthesame(T, p))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            FreeTree(p);
        }
        FreeTree(T);
    }
}
