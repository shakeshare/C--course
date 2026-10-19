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
void ReverseList(Linklist &L)
{
    Linklist p = L->next;
    L->next = NULL;
    while (p)
    {
        Linklist q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}
int main()
{
    Linklist A;
    CreateList(A, 10);
    ReverseList(A);
    Linklist p = A->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}