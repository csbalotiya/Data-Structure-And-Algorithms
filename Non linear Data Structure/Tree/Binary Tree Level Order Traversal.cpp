/*https://leetcode.com/problems/binary-tree-level-order-traversal/
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example :
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/

// Iterative 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if (!root) return ans;
        
        deque<TreeNode*> queue;
        
        queue.push_back(root);
        while(!queue.empty()){
            
            vector<int> row;
            int level = queue.size();
            
            while(level--){
                TreeNode* curr = queue.front();
                queue.pop_front();
            
                row.push_back(curr->val);
                
                if(curr->left)              queue.push_back(curr->left);
                if(curr->right)             queue.push_back(curr->right);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
