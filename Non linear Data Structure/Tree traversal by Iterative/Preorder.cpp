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
vector<int> preOrder(Node* root);
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
    ans = preOrder(root);

    for(int i = 0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}

vector<int> preOrder(Node* root){
    vector<int>v;
    Node *temp = NULL;
    stack<Node*> s;
    s.push(root);
    while(!s.empty() ){
        temp = s.top();
        s.pop();
        v.push_back(temp->data);
        if(temp->right != NULL) s.push(temp->right);
        if(temp->left != NULL) s.push(temp->left);
    }
    return v;
}
