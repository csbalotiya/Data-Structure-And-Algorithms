
//https://leetcode.com/problems/binary-tree-right-side-view/submissions/
// Complexity O[N]
class Solution {
public:
    // Iterative Approch
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *temp = q.front();
                if(i == 0){
                    res.push_back(temp->val);
                }
                q.pop();
                if(temp->right != NULL) q.push(temp->right);
                if(temp->left != NULL) q.push(temp->left);
            }
        }
        return res;
    }
    

    /*Recursive Approch
    int maxheight = 0;
    vector<int>res;
    void right(TreeNode *root, int level){
        if(root == NULL) return;
        if(level > maxheight){
            res.push_back(root->val);
            maxheight = level;
        }
        if(root->right != NULL) right(root->right, level+1); 
        if(root->left != NULL) right(root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int level = 1;
        right(root, level);
        return res;
    }*/
};
