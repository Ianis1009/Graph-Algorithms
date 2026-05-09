#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 15;
vector <int> adj[N];
bool vis[N];
int n, m;
bool DFS (int u, int cnt) {
    if (cnt == n)
        return true;
    
    for (int v : adj[u]) {
        if (vis[v] == false) {
            vis[v] = true;
            if (DFS(v, 1 + cnt))
                return true;

            vis[v] = false;
        }
    }

    return false;
}


int main () {

    cin >> n >> m;

    for (int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ok = false;

    for (int i = 1; i <= n; i++ ) {
        for (int i = 0; i < N; i++ ) {
            vis[i] = false;
        }
        vis[i] = true;
        if (DFS(i, 1)) {ok = true; break;}
    }

    if (ok) {
        cout << "Hamiltonian\n";
    } else {
        cout << "Not Hamiltonian\n";
    }
    
    return 0; 
}