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
    vector<int> inorderTraversal(TreeNode* root) {

        // Iterative approach - Inorder Traversal
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* temp = root;

        while (true) {
            if (temp != NULL) {
                st.push(temp);
                temp = temp->left;
            }
            else {
                if (st.empty() == true) break;
                temp = st.top();
                st.pop();
                inorder.push_back(temp->val);
                temp = temp->right;
            }
        }
        return inorder;
    }
};

int main() {
    Solution sol;
    return 0;
}