#include <bits/stdc++.h>
using namespace std; 
typedef struct Lnode
{
    int data;
    Lnode *next;
} Lnode, *Linklist;
void create(Linklist &L, int n)
{
    L = new Lnode;
    Linklist r;
    L->next = NULL;
    r = L;
    for (int i = 0; i < n; i++)
    {
        Linklist p = new Lnode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
void printlink(Linklist &L)
{
    Linklist p = L->next;
    while (p)
    {
        cout << p->data << ' ' ;
        p = p->next;
    }
    cout << endl;
}
void selectsort(Linklist &L)
{
    Linklist r, p, min;
    int temp;
    r = L->next;
    while (r->next != NULL)
    {
        p = r->next;
        min=r;
        while (p != NULL)
        {
            if (p->data < min->data)
            {
                min = p;
            }
            p = p->next;
        }
        temp = min->data;
        min->data = r->data;
        r->data = temp;
        r = r->next;
    }
}
int main()
{
    Linklist L;
    int n;
    cin >> n;
    create(L, n);
    selectsort(L);
    printlink(L);
    return 0;
}
