//https://practice.geeksforgeeks.org/problems/construct-tree-1/1#

class Solution{
    public:
    int ind=0;
    
    Node* create(int in[],int pre[],int start,int end)
    {
        if(start>end)    return NULL;
        
        Node* node = new Node(pre[ind++]);
        
        int pos;
        for(int i=start;i<=end;i++){
            if(in[i]==node->data){
                pos=i;
                break;
            }
        }
        
        node->left=create(in,pre,start,pos-1);
        node->right=create(in,pre,pos+1,end);
        return node;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
    
        return create(in,pre,0,n-1);
    }
};
