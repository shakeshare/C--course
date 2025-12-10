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
void BFS(Graph &G, int v)
{
    cout << v << " ";
    visited[v] = true;
    queue<int> Q;
    Q.push(v);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=1;i<=G.arcnum;i++)
        {
            if(G.arc[u][i]&&!visited[i])
            {
                cout << i << " ";
                visited[i] = true;
                Q.push(i);
            }
        }
    }
    
}
int BFStraverse(Graph &G)
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
            BFS(G, i);
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
    int ct=BFStraverse(G);
    cout << endl << ct <<  endl;
    return 0;
}