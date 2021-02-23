#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  struct node *left, *right;
  node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
void printInorder(struct node* node){
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
int main(){
    struct node *root = new node(1);
    root->left             = new node(2);
    root->right         = new node(3);
    root->left->left     = new node(4);
    root->left->right = new node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    printInorder(root);

return 0;
}
