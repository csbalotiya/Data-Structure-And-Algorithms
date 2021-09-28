//https://leetcode.com/problems/delete-node-in-a-bst/submissions/

class Solution {
public:
    vector<int> arr;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* merge(vector<int> &arr, int l, int r){
        if(l > r)   return NULL;
        int m = (l+r)/2;
        TreeNode* root = new TreeNode(arr[m]);
        root->left = merge(arr,l,m-1);
        root->right = merge(arr,m+1,r);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        inorder(root);
        arr.erase(remove(arr.begin(), arr.end(), key), arr.end());
        sort(arr.begin(), arr.end());
        for(int i : arr)cout<<i<<" ";
        
        TreeNode* res = merge(arr,0, arr.size()-1);
        return res;
    }
};



//Another
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(key<root->val)
            root->left = deleteNode(root->left, key);
        else if(key>root->val)
            root->right = deleteNode(root->right, key);
        else{
            if(!root->left)
                return root->right;
            if(!root->right)
                return root->left;
            TreeNode *rightSmallest = root->right;
            while(rightSmallest->left)
                rightSmallest = rightSmallest->left;
            rightSmallest->left = root->left;
            return root->right;
        }
        return root;    
    }
};
