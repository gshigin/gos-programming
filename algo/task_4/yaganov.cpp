#include <iostream>
#include <vector>


int main()
{

    int n, m;
    std::cin >> n >> m;

    std::vector<int> tmp(m, 1);
    std::vector<std::vector<int>> pt(n, tmp);

    //1 1 1 1 1
    //1 ij 1 1 1 
    
    for (int j = 1; j < n; j++) {
        for (int i = 1; i < m; i++) {
            pt[j][i] = pt[j - 1][i] + pt[j][i - 1];
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            std::cout << pt[j][i];
        }
        std::cout << std::endl;
    }

    return 0;
}