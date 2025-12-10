#include <bits/stdc++.h>
using namespace std;
#define Manum 100
#define Infinity 10000

typedef struct amgraph
{
    int vexs[Manum];
    int arcs[Manum][Manum];
    int vexnum, arcnum;
} Graph;
bool S[Manum];
int D[Manum];
int path[Manum];
void findpath(int v)
{
    int vex[Manum];
    int ct = 0;
    vex[ct] = v;
    ct++;
    while (path[v] != -1)
    {
        vex[ct] = path[v];
        ct++;
        v = path[v];
    }
    for (int i = ct-1; i >= 0; i--)
    {
        cout << vex[i] << " ";
    }
}
void dij(Graph G, int v0)
{
    int n = G.vexnum;
    for (int v = 0; v < n; v++)
    {
        S[v] = false;
        D[v] = G.arcs[v0][v];
        if (D[v] < Infinity && v != v0)
            path[v] = v0;
        else
            path[v] = -1;
    }
    S[v0] = true;
    D[v0] = 0;
    //
    int u;
    for (int i = 1; i < n; i++)
    {
        int min = Infinity;
        for (int w = 0; w < n; w++)
        {
            if (!S[w] && D[w] < min)
            {
                u = w;
                min = D[w];
            }
        }
        S[u] = true;
        for (int w = 0; w < n; w++)
        {
            if (!S[w] && (min + G.arcs[u][w] < D[w]))
            {
                D[w] = min + G.arcs[u][w];
                path[w] = u;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    Graph G;
    G.vexnum = n;
    for (int i = 0; i < n; i++)
    {
        G.vexs[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G.arcs[i][j];
        }
    }
    // input
    int a, b;
    char str[3];
    while (1)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
        {
            break;
        }
        else
        {
            dij(G, a);
            if (D[b] == Infinity)
              {  cout << "NO" << endl;
                continue;}
            else
            {
                cout << D[b] << endl;
            }
            findpath(b);
            cout << endl;
        }
    }
    return 0;
}