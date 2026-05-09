#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 100005;
vector <int> adj[N];

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
    vector<int> dist(n + 1, -1);
    queue <int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int v : adj[node]) {
            if (dist[v] == -1) {
                dist[v] = 1 + dist[node];
                q.push(v);
            }
        }
    }
    cout << '\n';
    //dist
    for (int i = 1; i <= n; i++ ) {
        cout << dist[i] << " ";
    }
    return 0;
}