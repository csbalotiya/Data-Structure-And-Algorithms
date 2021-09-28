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

Node* searchBST(Node* root, int x){

    if(root == NULL)
        return NULL;
    else if(x < root->data)
        return searchBST(root->left, x);
    else if(x > root->data)
        return searchBST(root->right, x);
    else
        return root;

}
int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout<<"Givern BST Tree : ";
    inorder(root);
    cout<<"\n\n";

    cout<<"Element Found : ";
    searchBST(root,3)? cout<<"Yes " : cout<<"No ";

    cout<<"\nElement Found : ";
    searchBST(root,13)? cout<<"Yes " : cout<<"No ";

    cout<<"\nElement Found : ";
    searchBST(root,-3)? cout<<"Yes " : cout<<"No ";
}




