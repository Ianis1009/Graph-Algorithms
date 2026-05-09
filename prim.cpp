#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 10007;
vector <pair<int, int>> adj[N];
bool vis[N];

int main () {

    int n, m;
    int cost = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++ ) {
        int u, w, v;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    while (!pq.empty()) {

        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u] == true)
            continue;
        vis[u] = true;
        cost += w;

        for (auto [v, c] : adj[u]) {
            if (!vis[v]) {
                pq.push({c, v});
            }
        }
    }
    cout << cost;
    return 0; 
}