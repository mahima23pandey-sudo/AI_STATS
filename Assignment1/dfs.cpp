#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(vector<vector<int>> &g, vector<int> &vis, int v, int n)
{
    vis[v] = 1;
    cout << v << " ";

    for(int i = 0; i < n; i++)
    {
        if(g[v][i] == 1 && vis[i] == 0)
            dfsUtil(g, vis, i, n);
    }
}

void dfs(vector<vector<int>> &g, int n, int s)
{
    vector<int> vis(n,0);
    dfsUtil(g, vis, s, n);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    int s;
    cin >> s;

    dfs(g, n, s);

    return 0;
}
