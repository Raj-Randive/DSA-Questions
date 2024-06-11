#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool getPath(TreeNode* root, vector<int>& arr, int x) {
    if (!root) return false;
    arr.push_back(root->val);

    if (root->val == x) return true;

    if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
        return true;
    }
    // If both return false then return false
    arr.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr;
    if (A == nullptr) return arr;
    getPath(A, arr, B);
    return arr;
}

int main() {
    Solution sol;
    return 0;
}