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
int DFS(Graph &G, int v)
{
    int w, ct = 1;
    visited[v] = true;
    for (w = 0; w < G.vexnum; w++)
    {
        if ((G.arc[v][w] != 0) && (!(visited[w])))
        {

            ct += DFS(G, w);
        }
    }
    return ct;
}
int DFStraverse(Graph &G)
{
    int i, ct = 0;
    for (i = 0; i < G.vexnum; ++i)
    {
        visited[i] = false;
    }
    for (i = 0; i < G.vexnum; ++i)
    {
        if (!visited[i])
        {
            ct++;
            int size = DFS(G, i);
            num.push_back(size);
        }
    }
    return ct;
}
int main()
{
    Graph G;
    cin >> G.vexnum >> G.arcnum;

    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
            G.arc[i][j] = 0;
    }
    for (int i = 0; i < G.arcnum; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G.arc[u][v] = 1;
        G.arc[v][u] = 1;
    }
    //  input
    cout << DFStraverse(G) << endl;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}