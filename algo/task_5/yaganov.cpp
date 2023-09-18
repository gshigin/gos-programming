#include <iostream>
#include <vector>
#include <queue>

int main()
{

    int N, S;

    std::cin >> N >> S;

    
    std::vector<std::vector<int>> mtx;
    {
        std::vector<int> tmp(N, 0);
        mtx = std::vector<std::vector<int>>(N, tmp);
    }
    int n;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> n;
            mtx[i][j] = n;
        }
    }

    std::vector<bool> visited(N, false);

    std::queue<int> q;
    q.push(S);
    //visited[S] = true;

    int lookup;

    while (!(q.empty())) {
        lookup = q.front();
        for (int i = 0; i < N; i++) {
            if (mtx[lookup][i] == 1 && !visited[i]) {
                q.push(i);
            }
        }
        visited[lookup] = true;
        q.pop();
    }

    int res = 0;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i])
            res++;
    }
    std::cout << res << std::endl;
    return 0;
}