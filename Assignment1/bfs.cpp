#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &g, int n, int s)
{
    vector<int> vis(n,0);
    queue<int> q;

    vis[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for(int i = 0; i < n; i++)
        {
            if(g[v][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                q.push(i);
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

    int s;
    cin >> s;

    bfs(g,n,s);

    return 0;
}
