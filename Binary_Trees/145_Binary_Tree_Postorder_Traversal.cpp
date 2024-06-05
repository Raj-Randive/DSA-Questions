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
    vector<int> postorderTraversal(TreeNode* root) {

        // Iterative Approach - Using 2 Stacks
        vector<int> postorder;
        stack<TreeNode*> s1, s2;

        if (root == NULL) return postorder;

        TreeNode* temp = root;
        s1.push(temp);


        while (!s1.empty()) {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }

        while (!s2.empty()) {
            TreeNode* node = s2.top();
            s2.pop();
            postorder.push_back(node->val);
        }

        return postorder;
    }
};

int main() {
    Solution sol;
    return 0;
}