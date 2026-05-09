#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 10009;
vector <int> adj[N];
bool vis[N];
int deg[N];

void DFS( int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v])
            DFS(v);
    }
}

bool connected ( int n ) {

    int start = -1;
    for ( int i = 1; i <= n; i++ ) {
        if (deg[i] > 0) {
            start = i;
            break;
        }
    }

    if (start == -1)
        return true;

    DFS(start);

    for (int i = 1; i <= n; i++ ) {
        if (deg[i] > 0 && vis[i] == false)
            return false;
    }
    return true;
}

int main () {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if (!connected(n)) {cout << "Not Eulerian\n"; return 0;}
    
    int cnt = 0;
    for (int i = 1; i <= n; i++ ) {
        if (deg[i] % 2 == 1) {cnt++;}
    }

    if (cnt == 0) 
        cout << "Eulerian Cycle\n";
    else if(cnt == 2)
        cout << "Eulerian Path\n";
    else
        cout << "Not Eulerian\n";

    return 0; 
}