/*https://leetcode.com/problems/n-ary-tree-level-order-traversal/
Given an n-ary tree, return the level order traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).


Example :
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        queue<Node*> q;
        
        if(root)
            q.push(root);
        else
            return res;
        
        int level;
        while(!q.empty()){
            vector<int> temp;
            level = q.size();
            while(level--){
                Node* node = q.front();
                q.pop();
                temp.push_back(node->val);
                for(auto x : node->children){
                    q.push(x);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
