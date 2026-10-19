#include <bits/stdc++.h>

using namespace std;

struct Crocodile
{
    double x, y;
};

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool dfs(int index, vector<vector<int>> &graph, vector<bool> &visited, vector<Crocodile> &crocs, double d)
{
    visited[index] = true;

    if (abs(crocs[index].x) + d >= 50 || abs(crocs[index].y) + d >= 50)
    {
        return true;
    }

    for (int neighbor : graph[index])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, graph, visited, crocs, d))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n;
    double d;
    cin >> n >> d;

    vector<Crocodile> crocs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> crocs[i].x >> crocs[i].y;
    }

    double min_distance = 1e9;
    vector<int> start_nodes;
    for (int i = 0; i < n; i++)
    {
        double dist_to_island = distance(0, 0, crocs[i].x, crocs[i].y) - 7.5;
        if (dist_to_island <= d)
        {
            start_nodes.push_back(i);
        }
        min_distance = min(min_distance, dist_to_island);
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (distance(crocs[i].x, crocs[i].y, crocs[j].x, crocs[j].y) <= d)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    bool can_escape = false;
    for (int start : start_nodes)
    {
        if (!visited[start])
        {
            if (dfs(start, graph, visited, crocs, d))
            {
                can_escape = true;
                break;
            }
        }
    }

    cout << fixed << setprecision(1) << min_distance << endl;
    if (can_escape)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}