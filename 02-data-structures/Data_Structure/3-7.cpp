#include <bits/stdc++.h>
using namespace std;
#define MAX 100
typedef struct
{
    int Q[MAX];
    int front;
    int rear;
    int tag;
} CQueue;

int enqueue(CQueue &C, int x)
{
    if (C.front == C.rear && C.tag == 1)
        return 0;
    C.Q[C.rear] = x;
    C.rear = (C.rear + 1) % MAX;
    if(C.front==C.rear)
    {C.tag = 1;}
    return 1;
}
int dequeue(CQueue &c,int &x)
{
    int x;
    if (c.front == c.rear && c.tag == 0)
    {
        return 0;
    }
    x = c.Q[c.front];
    c.front = (c.front + 1) % MAX;
    if(c.front==c.rear)
    {c.tag = 0;}
    return 1;
}
int main()
{
    return 0;
}