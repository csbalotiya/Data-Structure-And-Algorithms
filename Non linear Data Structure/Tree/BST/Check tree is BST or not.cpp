//https://practice.geeksforgeeks.org/problems/check-for-bst/1#

class Solution{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root, int l, int r){
        if(root == NULL)    return true;
        if(root->data < l || root->data > r)    return false;
        return isBST(root->left,l,root->data-1) && isBST(root->right,root->data+1,r);
    }
    
    bool isBST(Node* root) {
        return isBST(root, INT_MIN, INT_MAX);
    }
};
