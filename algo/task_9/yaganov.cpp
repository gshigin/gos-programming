#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // A large value to represent absence of edge

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mtx(n, vector<int>(n, -1)); // Initialize the adjacency matrix

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        mtx[u-1][v-1] = mtx[v-1][u-1] = w; // Undirected graph, so set both entries
    }

    vector<int> parent(n, -1);
    vector<int> cheapest(n, -1);
    vector<int> rank(n, 0);
    int numTrees = n;
    int mstWeight = 0;

    while (numTrees > 1) {
        for (int i = 0; i < n; ++i) {
            cheapest[i] = -1;
        }

        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                int w = mtx[u][v];
                if (w != -1) {
                    int set1 = parent[u] != -1 ? parent[u] : u;
                    int set2 = parent[v] != -1 ? parent[v] : v;

                    if (set1 != set2 && (cheapest[set1] == -1 || mtx[cheapest[set1]][set1] > w)) {
                        cheapest[set1] = v;
                    }
                }
            }
        }

        for (int node = 0; node < n; ++node) {
            if (cheapest[node] != -1) {
                int u = node;
                int v = cheapest[node];
                int w = mtx[u][v];

                int set1 = parent[u] != -1 ? parent[u] : u;
                int set2 = parent[v] != -1 ? parent[v] : v;

                if (set1 != set2) {
                    mstWeight += w;
                    --numTrees;
                    parent[set2] = set1;
                }
            }
        }
    }

    cout << "Weight of Minimal Spanning Tree: " << mstWeight << endl;

    return 0;
}
