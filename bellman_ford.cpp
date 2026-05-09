#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;

struct Edge {int u, v, w;};

int main () {

    int n, m, s;
    cin >> n >> m >> s;
    vector <Edge> edges;

    for (int i = 0; i < m; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> dist(n + 1, INF);
    dist[s] = 0;

    for (int i = 1; i < n; i++ ) {

        for (auto e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    bool negativeCycle = false;

    for (auto e : edges ) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            negativeCycle = true;
        }
    }

    if (negativeCycle)
        cout << "Negative cycle\n";
    else {
        for (int i = 1; i <= n; i++ ) {
            cout << dist[i] << ' ';
        }

    }
    return 0; 
}