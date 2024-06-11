#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void recur(TreeNode* root, int level, vector<int>& res) {
        if (root == nullptr) return;

        if (level == res.size()) res.push_back(root->val);
        recur(root->right, level + 1, res);
        recur(root->left, level + 1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recur(root, 0, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    return 0;
}