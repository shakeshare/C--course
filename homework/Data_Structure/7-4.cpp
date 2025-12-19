#include <bits/stdc++.h>
using namespace std;
typedef struct Bstnode
{
    int data;
    int count;
    struct Bstnode *llink;
    struct Bstnode *rlink;
} Bstnode, *Bstree;
void SearchInsert(Bstree &T, int key)
{
    Bstree q = T;
    Bstree parent = NULL;
    while (q)
    {
        if (q->data == key)
        {
            q->count++;
            return;
        }
        else
        {
            parent = q;
            if (key < q->data)
                q = q->llink;
            else
                q = q->rlink;
        }
    }
    Bstree s = new Bstnode;
    s->data = key;
    s->llink = NULL;
    s->rlink = NULL;
    if (parent == NULL)
        T = s;
    else
    {
        if (key < parent->data)
            parent->llink = s;
        else
            parent->rlink = s;
    }
}
//  void insert(Bstree &T, int key)
//  if(!T)
//  {
//      s=new Bstnode;
//      s->data=key;
//      s->llink=NULL;
//      s->rlink=NULL;
//      T=s;
//  }
//  else if(key<T->data)
//       insert(T->llink,key);
// else if(key>T->data)
//     insert(T->rlink,key);
