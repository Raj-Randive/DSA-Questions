#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                parentTrack[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentTrack[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // Marking all the node's parents.
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        markParents(root, parentTrack, target);

        // Visited Hash
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (curr_level++ == k) break;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if ((curr->left) && (!visited[curr->left])) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if ((curr->right) && (!visited[curr->right])) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if ((parentTrack[curr]) && (!visited[parentTrack[curr]])) {
                    q.push(parentTrack[curr]);
                    visited[parentTrack[curr]] = true;
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    return 0;
}