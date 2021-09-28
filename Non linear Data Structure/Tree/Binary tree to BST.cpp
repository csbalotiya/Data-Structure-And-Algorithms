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
vector<int> arr;
void inorder(Node* root, bool save = false){
    if(root == NULL) return;
    inorder(root->left, save);
    if(save == true)
        arr.push_back(root->data);
    else
        cout<<root->data<<" ";
    inorder(root->right, save);
}

Node* merge(vector<int>&arr, int l, int r){
    if(l > r)   return NULL;

    int mid = (l+r)/2;
    Node *root = new Node(arr[mid]);
    root->left = merge(arr,l,mid-1);
    root->right = merge(arr,mid+1,r);
    return root;
}

/*
void inorderArray(Node* root){
    if(root == NULL) return;
    inorderArray(root->left);
    arr.push_back(root->data);
    inorderArray(root->right);
}*/

void treetoBst(Node *root){

    inorder(root, true);
    sort(arr.begin(), arr.end());

    Node *BSTroot = merge(arr,0,arr.size()-1);

    cout<<"BST Tree : ";
    inorder(BSTroot);
}
int main(){

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(4);

    cout<<"Givern Tree : ";
    inorder(root);
    cout<<"\n\n";

    treetoBst(root);
}




