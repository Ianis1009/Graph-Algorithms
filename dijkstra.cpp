#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int N = 10005;
const int INF = 1e9;

vector <pair<int, int>> adj[N];
int dist[N];

int main () {

    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++ )
        dist[i] = INF;

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) 
            continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = w + dist[u];
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++ ) 
        cout << dist[i] << ' ' ;
    
    return 0; 
}