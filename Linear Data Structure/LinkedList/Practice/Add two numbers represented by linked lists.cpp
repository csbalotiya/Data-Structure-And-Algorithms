//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
//https://leetcode.com/problems/add-two-numbers-ii/
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





/*
Completer code for compiler 
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};
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

void print(Node *head){
    while(head != NULL){
        cout<<head->data<<"";
        head = head->next;
    }cout<<"\n";
}

int main(){

    vector<int> arr1 = {1,2,3};
    struct Node* head1 = new Node(arr1[0]);
	struct Node* temp1 = head1;
	for(int i = 1; i < arr1.size(); i++){
        temp1->next = new Node(arr1[i]);
        temp1 = temp1->next;
	}

    vector<int> arr2 = {3,9,2,9};
    struct Node* head2 = new Node(arr2[0]);
	struct Node* temp2 = head2;
	for(int i = 1; i < arr2.size(); i++){
        temp2->next = new Node(arr2[i]);
        temp2 = temp2->next;
	}

	class Solution ob;
	print(head1);
	print(head2);
	cout<<"Sum is : ";
	print(ob.addTwoLists(head1, head2));
}

*/
