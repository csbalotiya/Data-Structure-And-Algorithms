#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right ;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void insertBST(Node* root, int value){

    if(root->data < value){
        if(root->right == NULL){
            root->right = new Node(value);
            return;
        }
        insertBST(root->right, value);
    }
    if(root->data > value){
        if(root->left == NULL){
            root->left = new Node(value);
            return;
        }
        insertBST(root->left, value);
    }
}
int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    //root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout<<"Givern Tree : ";
    inorder(root);
    cout<<"\n\n";

    insertBST(root,1);
    cout<<"\nTree After Insertion : ";
    inorder(root);

    insertBST(root,12);
    cout<<"\nTree After Insertion : ";
    inorder(root);

    insertBST(root,15);
    cout<<"\nTree After Insertion : ";
    inorder(root);
}
