#include <iostream>

struct TreeNode {

    

    TreeNode() {
        L = nullptr;
        R = nullptr;
    }
    TreeNode(int& n) {
        data = n;
        L = nullptr;
        R = nullptr;
    }

    TreeNode* L;
    TreeNode* R;
    int data;

    void addData(int& n) {

        if (data == 0) {
            data = n;
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

        if (data == 0) {
            return i;
        }

        if (L == nullptr && R == nullptr) {
            return i+1;
        }

        int hl = L->findHeight(i+1);
        int hr = R->findHeight(i+1);

        if (hr > hl)
            return hr;
        return hl;

    }
};

int main()
{
    int a = 0;
    TreeNode* root = new TreeNode(a);

    int n = -1;
    while (n != 0) {
        std::cin >> n;
        root->addData(n);
    }

    int res = root->findHeight(0);
    
    std::cout << "height = " << res << std::endl;

    return 0;
}