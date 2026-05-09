#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;
vector <int> adj[N];
bool vis[N];

void dfs ( int node ) {
    vis[node] = true;
    cout << node << ' ';
    for (int v : adj[node]) {
        if (!vis[v])
            dfs(v);
    }
}

int main () {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;
    dfs(start);
    return 0; 
}