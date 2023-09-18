#include <iostream>

struct TreeNode {

    TreeNode() {
       L = nullptr;
       R = nullptr;
       isEmpty = true;
    }
    TreeNode(int& n) {
       data = n;
       L = nullptr;
       R = nullptr;
       isEmpty = false;
    }

    TreeNode* L;
    TreeNode* R;
    int data;
    bool isEmpty = true;

    void addData(int& n) {
        if (isEmpty) {
            data = n;
            isEmpty = false;
            return;
        }

        if (n == data)
            return;

        if (n < data) {
            if (L == nullptr) {
                L = new TreeNode(n);
            }
            else {
                L->addData(n);
            }
        }
        else {
            if (R == nullptr) {
                R = new TreeNode(n);
            }
            else {
                R->addData(n);
            }
        }

    }

    //void assignData()

    int findHeight(int i) {

        if (L == nullptr && R == nullptr) {
            return i+1;
        }
        int hl, hr;
        if (L == nullptr)
            hl = i;
        else hl = L->findHeight(i+1);

        if (R == nullptr)
            hr = i;
        else hr = R->findHeight(i + 1);

        if (hr > hl)
            return hr;
        return hl;

    }

    void findLeaves() {

        if (L == nullptr && R == nullptr) {
            std::cout << data << " ";
        }

        if (L != nullptr) {
                L->findLeaves();
        }

        if (R != nullptr) {
                R->findLeaves();
        }

    }
};

int main()
{
    TreeNode* root = new TreeNode();

    int n = -1;
    std::cin >> n;
    while (n != 0) {
        root->addData(n);
        std::cin >> n;
    }
    
    root->findLeaves();

    return 0;
}