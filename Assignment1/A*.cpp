#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int v;
    int f;
};

struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a.f > b.f;
    }
};

void astar(vector<vector<int>> &g, vector<int> &h, int n, int s, int goal)
{
    priority_queue<Node, vector<Node>, cmp> pq;
    vector<int> gCost(n, 1e9);
    vector<int> vis(n, 0);

    gCost[s] = 0;
    pq.push({s, h[s]});

    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        int u = cur.v;

        if(vis[u])
            continue;

        vis[u] = 1;
        cout << u << " ";

        if(u == goal)
            return;

        for(int v = 0; v < n; v++)
        {
            if(g[u][v] != 0)
            {
                int newCost = gCost[u] + g[u][v];
                if(newCost < gCost[v])
                {
                    gCost[v] = newCost;
                    pq.push({v, gCost[v] + h[v]});
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    vector<int> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];

    int s, goal;
    cin >> s >> goal;

    astar(g, h, n, s, goal);

    return 0;
}
