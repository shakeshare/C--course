#include <bits/stdc++.h>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *Linklist;
void CreateList(Linklist &L, int n)
{
    L = new LNode;
    L->next = NULL;
    Linklist r, p;
    int i;
    r = L;
    for (i = 0; i < n; ++i)
    {
        p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
int main()
{
    Linklist L, P, a, b, tail, c;
    CreateList(L, 10);
    CreateList(P, 10);
    c = L;
    a = L->next;
    b = P->next;
    tail = c;
    while (a && b)
    {
        if (a->data < b->data)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    tail->next = a ? a : b;
    delete P;
    Linklist p = c->next;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
    return 0;
}