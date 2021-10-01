// Time Complexity O[N+M]
//Space Complexity O[N]
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

void inorderT(Node* root){
    if(root == NULL) return;
    inorderT(root->left);
    cout<<root->data<<" ";
    inorderT(root->right);
}
void inorder(Node* root, vector<int>& arr){
    if(root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node* BuildBST(vector<int>&arr, int l, int r){
    if(l > r)   return NULL;

    int mid = (l+r)/2;
    Node *root = new Node(arr[mid]);
    root->left = BuildBST(arr,l,mid-1);
    root->right = BuildBST(arr,mid+1,r);
    return root;
}

Node* mergeTrees(Node* root1, Node* root2){

    vector<int>arr1;
    inorder(root1, arr1);
    vector<int>arr2;
    inorder(root2, arr2);

    cout<<"BST1 : ";    inorderT(root1);
    cout<<"\nBST2 : ";  inorderT(root2);

    vector<int> merged;
    int n1 = arr1.size(), n2 = arr2.size(), i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            merged.push_back(arr1[i]);
            i++;
        }else{
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while(i < n1){
        merged.push_back(arr1[i]);
        i++;
    }
    while(j < n2){
        merged.push_back(arr2[j]);
        j++;
    }

    return BuildBST(merged, 0, merged.size()-1);
}

int main(){
    /* Create following tree as first balanced BST1
        100
        / \
        50 300
    / \
    20 70
    */
    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    /* Create following tree as second balanced BST2
            80
        / \
        40 120
    */
    Node *root2 = new Node(80);
    root2->left     = new Node(40);
    root2->right = new Node(120);

    Node *mergedTreeNode = mergeTrees(root1, root2);

    cout << "\nFollowing is Inorder traversal of the merged tree \n";
    inorderT(mergedTreeNode);

    return 0;
}
