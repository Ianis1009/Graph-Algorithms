#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int N = 10009;
vector <int> adj[N];
int color[N];

bool BFS(int start ) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {return false;}
        }
    }

    return true;
}

int main () {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++ ) {
        color[i] = -1;
    }

    for (int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ver = true;
    for (int i = 1; i <= n; i++ ) {
        if (color[i] == -1) {
            if (!BFS(i)) 
                ver = false;
        }
    }

    if(ver)    
        cout << "Bipartite\n";
    else
        cout << "Not Bipartite\n";

    return 0;
}