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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // Iterative Approach using stack !!

        vector<int> preorder;
        if (root == NULL) return preorder;

        stack<TreeNode*> stk;
        stk.push(root);

        TreeNode* temp = NULL;
        while (!stk.empty()) {
            temp = stk.top();
            stk.pop();
            preorder.push_back(temp->val);
            if (temp->right) stk.push(temp->right);
            if (temp->left) stk.push(temp->left);
        }

        return preorder;
    }
};

int main() {
    Solution sol;
    return 0;
}