#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isLeaf(Node* node) {
        if (node->left == nullptr && node->right == nullptr) return true;
        else return false;
    }

    void addLeftBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) ans.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& ans) {
        // Add in Reverse Order

        Node* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }

        for (int i = temp.size() - 1; i >= 0; --i) {
            ans.push_back(temp[i]);
        }
    }

    void addLeafNodes(Node* root, vector<int>& ans) {

        if (isLeaf(root)) ans.push_back(root->data);

        if (root->left) addLeafNodes(root->left, ans);
        if (root->right) addLeafNodes(root->right, ans);
    }

public:
    vector <int> boundary(Node* root)
    {
        vector<int> ans;
        if (!root) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);

        addLeftBoundary(root, ans);
        addLeafNodes(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};

int main() {
    Solution sol;
    return 0;
}