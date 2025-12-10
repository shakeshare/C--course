#include <bits/stdc++.h>
using namespace std;
#define Maxn 30
#define Maxm 100
typedef struct
{
    int vex[Maxm];
    int arc[Maxn][Maxn];
    int vexnum, arcnum;
} Graph;
bool visited[Maxn];
vector<int> num;
void DFS(Graph &G, int v)
{
    int w;
    cout << v << " ";
    visited[v] = true;
    for (w = 1; w <= G.vexnum; w++)
    {
        if ((G.arc[v][w] != 0) && (!(visited[w])))
        {
            DFS(G, w); 
        }
    }
}
int DFStraverse(Graph &G)
{
    int i, ct = 0;
    for (i = 1; i <= G.vexnum; ++i)
    {
        visited[i] = false;
    }
    for (i = 1 ;i <= G.vexnum; ++i)
    {
        if (!visited[i])
        {

            ct++;
            DFS(G, i);
        }
    }
    return ct;
}
int main()
{
    Graph G;
    cin >> G.arcnum;
    G.vexnum = G.arcnum;    
    for (int i = 1; i <= G.vexnum; i++)
    {
        for (int j = 1; j <= G.vexnum; j++)
          cin >>  G.arc[i][j] ;
    }
    int ct=DFStraverse(G);
    cout << "\n" << ct <<  endl;
    return 0;
}