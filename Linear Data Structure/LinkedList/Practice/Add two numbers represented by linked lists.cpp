//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

class Solution{
    public:
    Node* reverse(Node* head){
		Node* current = head;
		Node *prev = NULL, *next = NULL;
		while (current != NULL) {
		    next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
	    return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *a = reverse(first);
        Node *b = reverse(second);
        Node *res = new Node(0);
        Node *head = res;
        int carry = 0;
        while(a != NULL || b != NULL){
            
            int x = (a != NULL) ? a->data : 0; 
            int y = (b != NULL) ? b->data : 0; 
            int sum = carry+x+y;
            carry = sum/10;
            res->next = new Node(sum%10);
            res = res->next;
            
            if(a != NULL) a = a->next;
            if(b != NULL) b = b->next;
        }
        if(carry > 0)
            res->next = new Node(carry);
        Node* ans = reverse(head->next);

        return ans;
    }
};
