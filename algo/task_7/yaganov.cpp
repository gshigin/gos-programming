#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

struct compareVerts {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main()
{

    int N, M; //verts, edges

    std::cin >> N >> M;

    std::unordered_map<int, std::vector<std::pair<int, int>>> edges;

    int u, v, w;
    for (int i = 0; i < M; i++) {
        
        std::cin >> u >> v >> w;
        if(edges.find(u) == edges.end())
            edges[u-1] = std::vector<std::pair<int, int>>();
        edges[u-1].push_back(std::make_pair(v-1, w));
    }

    std::vector<int> distances( N, 30000 );
    distances[0] = 0;

    bool notChanged = false;

    for (int iter = 1; iter < N; iter++) {

        if (notChanged)
            break;
        notChanged = true;

        //

        //std::vector<bool> visited(N, false);

        for (int u = 0; u < N; u++) {

            //visited[i] = true;

            for (const auto& pair : edges[u]) {
                v = pair.first;
                w = pair.second;
                if (distances[u] < 30000 && distances[u] + w < distances[v]) {
                    distances[v] = distances[u] + w;
                    notChanged = false;
                }
            }
        }
    }

    for (int i = 0; i < distances.size(); i++) {
        std::cout << distances[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}

