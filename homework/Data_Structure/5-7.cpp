#include <bits/stdc++.h>
using namespace std;
typedef struct Bitnode
{
    char data;
    struct Bitnode *lchild, *rchild;
} Bitnode, *Bitree;
Bitree key;
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
int road(Bitree T)
{
    if (T == NULL)
        return 0;
    int count = 0;
    queue<Bitree> q;
    q.push(T);
    while (!q.empty())
    {
        int width = q.size();
        for (int i = 0; i < width; i++)
        {
            Bitree p = q.front();
            q.pop();
            if (p->lchild != NULL)
                q.push(p->lchild);
            if (p->rchild != NULL)
                q.push(p->rchild);
        }
        count++;
        key=q.back();
    }
    return count;
 }


int main()
{
    Bitree T;
    create(T);
    cout << road(T) << endl;
    return 0;
}
