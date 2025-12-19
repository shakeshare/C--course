#include <bits/stdc++.h>
using namespace std;
vector<int> v;
typedef struct Bitnode
{
    int data;
    struct Bitnode *lchild;
    struct Bitnode *rchild;
} Bitnode, *Bitree;
void traver(Bitree T)
{
    if (T)
    {
        traver(T->lchild);
        v.push_back(T->data);
        traver(T->rchild);
    }
}
bool IsBstree(const vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i] >= v[i + 1])
            return false;
    }
    return true;
}