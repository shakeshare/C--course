#include <bits/stdc++.h>
using namespace std;
typedef struct BstNode
{
    int data;
    struct BstNode *lchild, *rchild;
} BsTNode, *BsTree;
int parent=-1;
int Insert(BsTree &T,int e)
{
    if(!T)
    {
        BsTree s=new BstNode;
        s->data=e;
        s->lchild=s->rchild=NULL;
        T=s;
        return parent;
    }
    parent=T->data;
    if(e<T->data)
        { return Insert(T->lchild,e);}
    else
       {  return Insert(T->rchild,e);}
}
int main()
{
     int n;
     cin>>n;
     BsTree T=NULL;

     for(int i=0;i<n;i++)
     {
         int e;
         cin>>e;
         int p=Insert(T,e);
         cout<<p<<endl;
     }
        return 0;
}