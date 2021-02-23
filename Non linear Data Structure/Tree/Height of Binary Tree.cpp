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
int height(struct node* node){
        if(node == NULL)
            return 0;
        int l = height(node->left);
        int r = height(node->right);
        if(l>r)
            return l+1;
        else
            return r+1;
    }
int main(){
    struct node *root = new node(1);
    root->left             = new node(2);
    root->right         = new node(3);
    root->left->left     = new node(4);
    root->left->right = new node(5);

    cout << "Height of binary tree is : "<<height(root);
return 0;
}
