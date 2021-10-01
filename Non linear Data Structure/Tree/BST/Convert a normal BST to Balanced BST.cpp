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
void preOrder(Node* node){
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

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

void treetoBst(Node *root){

    inorder(root, true);
    sort(arr.begin(), arr.end());

    Node *BSTroot = merge(arr,0,arr.size()-1);

    cout<<"BST Tree INORDER : ";
    inorder(BSTroot);
    cout<<"\nBST Tree PREORDER : ";
    preOrder(BSTroot);
}
int main(){

/* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);


    cout<<"Givern Tree : ";
    inorder(root);
    cout<<"\n\n";

    treetoBst(root);
}




