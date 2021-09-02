//https://practice.geeksforgeeks.org/problems/reorder-list/1

/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.*/

void reorderList(Node* head) {
    // Your code here
    Node *f_ptr=head,*s_ptr=head;
    if(head==NULL && head->next!=NULL)
        return;
    while(f_ptr!=NULL && f_ptr->next!=NULL){
        f_ptr=f_ptr->next->next;
        s_ptr=s_ptr->next;
    }
    
    Node *curr=s_ptr,*prev=0,*net=0;
    while(curr!=NULL)    {
        net = curr->next;
        curr->next=prev;
        prev=curr;
        curr=net;
    }
    Node *n1 = head,*n2=prev,*tmp;
    while(n2->next != NULL){
        tmp = n1->next;
        n1->next = n2;
        n1 = tmp;
        
        tmp = n2->next;
        n2->next=n1;
        n2 = tmp;   
    }
}




//https://leetcode.com/problems/reorder-list/

class Solution {
public:
    void reorderList(ListNode* root) {

        vector<int> v;
        int n = 0;
        ListNode *head = root;
        while(head != NULL){
            n++;
            v.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = 0, k = 0;
        while(k < n){
            if(k%2 == 0){
                root->val = v[i];
                i++;
            }else{
                root->val = v[n-1-j];
                j++;
            }
            k++;
            root = root->next;
        }
    }
};
