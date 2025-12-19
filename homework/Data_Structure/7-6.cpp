#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
typedef Node *hashTable[10];
int H(int k)
{
    return k % 10;
}
void Insert(hashTable &ht, int k)
{
    int Index = H(k);
    Node *p = new Node;
    p->data = k;
    p->next = ht[Index];
    ht[Index] = p;
}
int Delete(hashTable &ht, int k)
{
    int Index = H(k);
    Node *p = ht[Index];
    if (p == NULL)
        return -1;
    if (p->data == k)
    {
        ht[Index] = p->next;
        delete p;
        return 1;
    }
    while (p->next != NULL && p->next->data != k)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        return -1;
    }
    else
    {
        Node *q = p->next->next;
        delete p->next;
        p->next = q;
        return 1;
    }
}