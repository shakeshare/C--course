#include <bits/stdc++.h>
using namespace std;

#define MaxN 20
#define Infinity 10000

struct Graph {
    int vexs[MaxN];
    int arcs[MaxN][MaxN];
    int vexnum;
};

bool S[MaxN];
int D[MaxN];
int path[MaxN];

void findpath(int v) {
    vector<int> vex;
    while (v != -1) {
        vex.push_back(v);
        v = path[v];
    }
    for (int i = vex.size() - 1; i >= 0; i--) {
        cout << vex[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
}

void dij(Graph &G, int v0) {
    int n = G.vexnum;
    for (int v = 0; v < n; v++) {
        S[v] = false;
        D[v] = G.arcs[v0][v];
        if (D[v] < Infinity)
            path[v] = v0;
        else
            path[v] = -1;
    }
    S[v0] = true;
    D[v0] = 0;
    path[v0] = -1;

    for (int i = 1; i < n; i++) {
        int minDist = Infinity, u = -1;
        for (int w = 0; w < n; w++) {
            if (!S[w] && D[w] < minDist) {
                u = w;
                minDist = D[w];
            }
        }
        if (u == -1) break; // 剩余不可达，提前结束
        S[u] = true;

        for (int w = 0; w < n; w++) {
            if (!S[w] && G.arcs[u][w] < Infinity && D[u] + G.arcs[u][w] < D[w]) {
                D[w] = D[u] + G.arcs[u][w];
                path[w] = u;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    Graph G;
    G.vexnum = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G.arcs[i][j];

    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;

        dij(G, a);
        if (D[b] == Infinity) {
            cout << "NO" << endl;
        } else {
            cout << D[b] << endl;
            findpath(b);
        }
    }
    return 0;
}
