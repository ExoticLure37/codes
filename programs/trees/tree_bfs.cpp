#include <bits/stdc++.h>
#include <queue>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void bfsTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->val << " ";

        // Enqueue the left child if it exists.
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // Enqueue the right child if it exists.
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "BFS Traversal: ";
    bfsTraversal(root);
    return 0;
}
