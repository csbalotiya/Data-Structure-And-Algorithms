//https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        this->data = val;
        this->left = this->right = NULL;
    }
};

Node* BST(Node *root, int val, Node*& suc){

    if(root == NULL)
        return root = new Node(val);
    if(val < root->data){
        suc = root;
        root->left = BST(root->left, val, suc);
    }
    else if(val > root->data){
        root->right = BST(root->right, val, suc);
    }
    return root;
}

void fun(int arr[], int n){

    Node* root = NULL;
    for(int i = n-1; i >= 0; i--){
        Node *suc = NULL;
        root = BST(root,arr[i],suc);
        if(suc)
            arr[i] = suc->data;
        else
            arr[i] = -1;
    }
}
int main(){
    int arr[] = {8,58,71,18,31,32,63,92,43,3,91,93,25,80,28};
    int n = sizeof(arr) / sizeof(arr[0]);

    fun(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
