#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1009;
struct Edge {int u, v, w;};
vector <Edge> edges;
int parent[N], r[N];

int find ( int x ) {
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite (int a, int b) {
    a = find(a);
    b = find(b);

    if (b != a) {
        if (r[a] < r[b]) {
            swap(a, b);
        }
        parent[b] = a;
        r[a] += r[b];
    }
}

int main () {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++ ) {
        parent[i] = i;
        r[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {return a.w < b.w;});

    int cost = 0;
    for (auto e : edges) {
        if (find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            cost += e.w;
        }
    }
    cout << cost;
    return 0;
}