#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform DFS traversal on a binary tree
void dfs(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";

    dfs(root->left);
    dfs(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "DFS Traversal: ";
    dfs(root);
    return 0;
}
