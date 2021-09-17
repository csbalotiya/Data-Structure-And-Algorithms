
//Iterative
vector<int> leftView(Node *root){
   vector<int> ans;
   if(root == NULL) return ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       int n = q.size();
       for(int i = 0; i < n; i++){
           Node* temp = q.front();
           if(i == 0){
               ans.push_back(temp->data);
           }
           q.pop();
           if(temp->left != NULL)
                q.push(temp->left);
           if(temp->right != NULL)
                q.push(temp->right);
       }
   }
   return ans;
}


//Recursion 
int maxlevel = 0;
vector<int> res;
void left(Node *root, int level){
    if(root == NULL)
        return;
    if(level > maxlevel){
        res.push_back(root->data);
        //cout<<root->data<<" ";
        maxlevel = level;
    }

    left(root->left, level+1);
    left(root->right, level+1);
}
vector<int> leftView(Node *root){
   left(root,1);
   return res;
}
