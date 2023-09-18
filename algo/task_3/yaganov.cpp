#include <iostream>
#include <vector>


std::vector<int> MergeSort(std::vector<int> V) {

    if (V.size() == 1)
        return V;
    else if (V.size() == 2) {
        if (V[0] < V[1])
            return V;
        else {
            int a = V[0];
            V[0] = V[1];
            V[1] = a;
            return V;
        }
    }

    std::vector<int> v1(V.begin(), V.begin()+(V.size()/2)+1);
    std::vector<int> v2(V.begin() + ((V.size() / 2) + 1), V.end());

    auto vec1 = MergeSort(v1);//получили век
    auto vec2 = MergeSort(v2);

    std::vector<int> res;
    int i = 0;
    int j = 0;
    while(!(j == vec2.size() && i == vec1.size())) {
        if (vec1[i] < vec2[j]) {
            res.push_back(vec1[i]);
            i++;
        }
        else {
            res.push_back(vec2[j]);
            j++;
        }
        if (i == vec1.size()) {
            while (j != vec2.size()) {
                res.push_back(vec2[j]);
                j++;
            }
        }
        if (j == vec2.size()) {
            while (i != vec1.size()) {
                res.push_back(vec1[i]);
                i++;
            }
        }
    }
    return res;
}

int main()
{
    int n, k;
    std::vector<int> V;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> k;
        V.push_back(k);
    }

    auto res = MergeSort(V);

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}