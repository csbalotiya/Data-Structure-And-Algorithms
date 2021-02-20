#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data)    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
vector<int> inOrder(Node* root);
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->right = new Node(8);

    vector<int> ans;
    ans = inOrder(root);

    for(int i = 0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}

vector<int> inOrder(Node* root){
    vector<int>v;
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || s.empty() == false){
        while (curr !=  NULL)   {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        v.push_back(curr->data);
        curr = curr->right;
    }
    return v;
}
