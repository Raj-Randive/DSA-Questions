
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void postOrder(Node* node) {

        vector<int> in, pre, post;
        stack< pair<Node*, int> > st;

        if (node == nullptr) return;
        st.push({ node, 1 });

        while (!st.empty()) {

            auto it = st.top();
            st.pop();

            // Part of Preorder
            if (it.second == 1) {
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->left) {
                    st.push({ it.first->left, 1 });
                }
            }

            // Part of Inorder
            else if (it.second == 2) {
                in.push_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->right) {
                    st.push({ it.first->right, 1 });
                }
            }

            // Part of Postoder. Donot increment
            else {
                post.push_back(it.first->data);
            }
        }

        for (auto i : in) {
            cout << i << " ";
        }
        cout << "\n";

        for (auto i : pre) {
            cout << i << " ";
        }
        cout << "\n";

        for (auto i : post) {
            cout << i << " ";
        }
        cout << "\n";
    }

};


int main() {
    Solution sol;
    return 0;
}