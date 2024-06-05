#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <int> bottomView(Node* root) {
        // Bottom View of Binary Tree
        vector<int> ans;

        map<int, int> mpp;
        queue<pair<Node*, int>> q;

        q.push({ root, 0 });

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* temp = it.first;
            int line = it.second;

            mpp[line] = temp->data;

            if (temp->left) q.push({ temp->left, line - 1 });
            if (temp->right) q.push({ temp->right, line + 1 });
        }
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    return 0;
}