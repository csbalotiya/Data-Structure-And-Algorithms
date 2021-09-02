//https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/
//https://www.interviewbit.com/old/problems/max-sum-path-in-binary-tree/

/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/

class Solution {
public:
    int fun(TreeNode* root, int &res){
        if(root == NULL) return 0;
        int l = max(0,fun(root->left, res));
        int r = max(0,fun(root->right, res));

        int case1 = max(l,r)+root->val;
        int case2 = max(root->val, l+r+root->val);
        res = max(res, max(case1, case2));
        return case1;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        fun(root, res);
        return res;
    }
};
