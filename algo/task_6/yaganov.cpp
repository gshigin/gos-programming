#include <iostream>
#include <vector>
#include <queue>

struct compareVerts {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main()
{

    //std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int>>, compareVerts> pq;

    int N, S, F;
    std::cin >> N >> S >> F;

    std::vector<std::vector<int>> mtx;
    {
        std::vector<int> tmp(N, -1);
        mtx = std::vector<std::vector<int>>(N, tmp);
    }
    int w;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> w;
            mtx[i][j] = w;
        }
    }

    std::vector<int> distances(N, INT32_MAX);
    std::vector<int> prevs(N, -1);
    std::vector<bool> used(N, false);

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int>>, compareVerts> pq;
    int currV = S;
    distances[currV] = 0;
    prevs[currV] = currV;
    used[currV] = true;
    pq.push(std::make_pair(0,currV));
    

    while (!(pq.empty())) {
        
        currV = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();
        std::cout << "popped from pq!" << std::endl;

        if (F == currV)
            break;

        for (int i = 0; i < N; i++) {
            int dist = mtx[currV][i]; //number
            
            if (dist == -1)
                continue;

            std::cout << "now in " << currV << "; pushed " << i << std::endl;
            
            int relaxedDist = distances[currV] + dist;
            if (relaxedDist < distances[i]) {
                std::cout << "now in " << currV << "; Relaxed " << i << " to d=" << relaxedDist << std::endl;
                distances[i] = relaxedDist;
                prevs[i] = currV;
                pq.push(std::make_pair(relaxedDist, i));

            }
            used[i] = true;
        }
    }
    std::vector<int> route;
    if (prevs[F] == -1) {
        std::cout << -1 << std::endl;
    }
    else {
        
        int i = F;
        while (i != prevs[i]) {
            route.push_back(i);
            i = prevs[i];
        }
        route.push_back(S);
    }

    std::reverse(route.begin(), route.end());

    for (int i = 0; i < route.size(); i++) {
        std::cout << route[i] << ",";
    }
    std::cout << std::endl;

    return 0;
}

