/*https://leetcode.com/problems/n-ary-tree-postorder-traversal/
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]*/



// Recursively
class Solution {
public:
    void order(Node* root,vector<int>& result) {
        if (root == NULL) return;
        for (Node* child : root -> children) 
            order(child, result);
        result.push_back(root -> val);
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        order(root,v);
        return v;
    }
};

//Iterative

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;
        if(!root) {}
        else
        {
            stack<Node*>s;
            s.push(root);
            while(!s.empty())
            {
                Node *node = s.top();
                s.pop();
                ans.push_back(node->val);
                for(auto i:node->children)
                {
                    s.push(i);
                }
            }
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};
