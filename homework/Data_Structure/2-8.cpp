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
    Linklist L,a,p;
    CreateList(L, 10);
    int mink,maxk;
    cin>>mink>>maxk;
    a=L;
    p=L->next;
    while(p!=NULL){
        if(p->data>mink && p->data<maxk )
       {a->next=p->next;
        delete p;
        p=a->next;}
        else{
        a=a->next;
        p=p->next;
        }
        
    }
    Linklist o = L->next;
    while (o)
    {
        cout << o->data << " ";
        o = o->next;
    }
    return 0;
} 
