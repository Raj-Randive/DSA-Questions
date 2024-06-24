/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>
int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& mpp, BinaryTreeNode<int>* target) {
    queue<BinaryTreeNode<int>*> q;
    q.push(target);

    map<BinaryTreeNode<int>*, int> visited;
    visited[target] = 1;

    int maxi = 0;

    while (!q.empty()) {

        int size = q.size();
        int flag = 0;

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int>* temp = q.front();
            q.pop();

            if (temp->left && !visited[temp->left]) {
                flag = 1;
                visited[temp->left] = 1;
                q.push(temp->left);
            }
            if (temp->right && !visited[temp->right]) {
                flag = 1;
                visited[temp->right] = 1;
                q.push(temp->right);
            }
            if (mpp[temp] && !visited[mpp[temp]]) {
                flag = 1;
                visited[mpp[temp]] = 1;
                q.push(mpp[temp]);
            }
        }
        if (flag) maxi++;
    }
    return maxi;
}

BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& mpp, int target) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* res;
    while (!q.empty()) {
        BinaryTreeNode<int>* temp = q.front();
        if (temp->data == target) res = temp;
        q.pop();

        if (temp->left) {
            mpp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right) {
            mpp[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return res;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map< BinaryTreeNode<int>*, BinaryTreeNode<int>* > mpp;
    BinaryTreeNode<int>* target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}
