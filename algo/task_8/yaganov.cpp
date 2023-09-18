#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

std::random_device rd;
std::mt19937 gen(rd());

bool atLeastOneFalse(vector<bool>& used) {
    for (int i = 0; i < used.size(); i++) {
        if (!used[i])
            return true;
    }
    return false;
}

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<bool> used(n, false);

    vector<vector<int>> edges;

    int b, e, w;

    for (int i = 0; i < m; i++) {
        cin >> b >> e >> w;
        edges.push_back({ b,e,w });
    }

    std::uniform_int_distribution<> dis(1, n);
    int initNode = dis(gen);

    vector<vector<int>> goodEdges;
    
    int candidate = -1;
    int dist = 100001;
    for (int i = 0; i < m; i++) {
        if ((edges[i][0] == initNode || edges[i][1] == initNode) && edges[i][2] < dist) //no self vertices
        {
            candidate = i;
            dist = edges[i][2];
        }
    }
    goodEdges.push_back(edges[candidate]);
    used[edges[candidate][0]-1] = true;
    used[edges[candidate][1]-1] = true;

    while (atLeastOneFalse(used)) {
        candidate = -1;
        dist = 100001;
        int u, v, w;
        for (int i = 0; i < edges.size(); i++) {
            u = edges[i][0];
            v = edges[i][1];
            w = edges[i][2];
            if (used[u-1] ^ used[v-1] && w < dist) {
                dist = w;
                candidate = i;
            }
        }

        if (candidate != -1) {
            goodEdges.push_back(edges[candidate]);
            used[edges[candidate][0]-1] = true;
            used[edges[candidate][1]-1] = true;
        }
    }

    //std::cout << "size goodEdges = " << goodEdges.size() << endl;

    int res = 0;
    for (const auto& e : goodEdges) {
        res += e[2];
    }
    std::cout << res << endl;


    return 0;
}
