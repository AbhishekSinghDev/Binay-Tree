#include<bits/stdc++.h>
using namespace std;

class BinaryTree {
    public:
        struct node {
            int val;
            struct node *left;
            struct node *right;

            node(int data) {
                val = data;
                left = NULL;
                right = NULL;
            }
        };

        // BFS (BREADTH FIRST SEARCH)
        // Level Order Travarsal
        vector<vector<int>> levelOrderTravarsal(node *root) {
            vector<vector<int>> ans;
            if(root == NULL) {
                return ans;
            }
            queue<node*> q;
            q.push(root);
            while(!q.empty()) {
                int size = q.size();
                vector<int> level;
                for(int i=0; i<size; i++) {
                    node *curr = q.front();
                    q.pop();
                    if(curr->left != NULL) q.push(curr->left);
                    if(curr->right != NULL) q.push(curr->right);
                    level.push_back(curr->val);
                }
                ans.push_back(level);
            }
            return ans;
        }

        // DFS (DEPTH FIRST SEARCH)
        // Pre-Order Travarsal (root, left, right)
        void preOrderTravarsal(node *curr, vector<int> &pre) {
            if(curr == NULL) {
                return;
            }

            pre.push_back(curr->val);
            preOrderTravarsal(curr->left, pre);
            preOrderTravarsal(curr->right, pre);

        }

        // Post-Order Travarsal (left, right, root)
        void postOrderTravarsal(node *curr, vector<int> &post) {
            if(curr == NULL) {
                return;
            }

            postOrderTravarsal(curr->left, post);
            postOrderTravarsal(curr->right, post);
            post.push_back(curr->val);
        }

        // In-Order Travarsal (left, root, right)
        void inOrderTravarsal(node *curr, vector<int> &in) {
            if(curr == NULL) {
                return;
            }

            inOrderTravarsal(curr->left, in);
            in.push_back(curr->val);
            inOrderTravarsal(curr->right, in);
        }
};

int main() {
    return 0;
}