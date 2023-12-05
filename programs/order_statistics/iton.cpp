#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left;
  struct node *right;
  int size;
};
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " -> ";
    inorder(root->right);
  }
}
struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);
  return node;
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
int size(struct node* root){
    if(root==NULL){
        return 0;
    }
    int ls=size(root->left);
    int rs=size(root->right);
    root->size=ls+rs+1;
    return root->size;
}
int i_to_n(struct node* root,int i){
    int ls=size(root->left);
    int cr=ls+1;
    if(i==cr){
        return root->key;
    }
    if(i<cr){
        return(i_to_n(root->left,i));
    }
    if(i>cr){
        return(i_to_n(root->right,i));
    }
}

int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: "<<endl;
  inorder(root);

  root = deleteNode(root, 10);
  cout << "Inorder traversal: "<<endl;
  inorder(root);

  int x=i_to_n(root,3);
  cout<<x;

}