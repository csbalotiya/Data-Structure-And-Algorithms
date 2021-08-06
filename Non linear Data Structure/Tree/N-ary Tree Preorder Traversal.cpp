/*https://leetcode.com/problems/n-ary-tree-preorder-traversal/

Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)


Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
*/
class Solution {
public:
    void order(Node* root,vector<int>& result) {
        if (root == NULL) return;
        result.push_back(root -> val);
        for (Node* child : root -> children) 
            order(child, result);
    }
    vector<int> preorder(Node* root) {
        vector<int> v;
        order(root,v);
        return v;
    }    
};
