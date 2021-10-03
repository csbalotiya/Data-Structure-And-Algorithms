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
void print(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }cout<<"\n";
}
Node* mergeList(Node* head1,Node* head2){

    if(head1 == NULL or head2 == NULL)
        return head1 != NULL ? head1 : head2;

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    Node* temp = new Node(-1);
    Node* prev = temp;

    while(ptr1 != NULL and ptr2 != NULL){
        if(ptr1->data < ptr2->data){
            prev->next = ptr1;
            ptr1 = ptr1->next;
        }else{
            prev->next = ptr2;
            ptr2 = ptr2->next;
        }
        prev = prev->next;
    }

    prev->next = ptr1 != NULL ? ptr1 : ptr2;
    return temp->next;
}
// Finding mid node
Node* midNode(Node* head){
    if(head == NULL or head->next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL and fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* head) {

    if(head == NULL or head->next == NULL)
        return head;

    Node* mid = midNode(head);
    Node* nHead = mid->next;
    mid->next = NULL;
    Node* l1 = mergeSort(head);
    Node* l2 = mergeSort(nHead);
    return mergeList(l1,l2);
}

int main(){
  vector<int> arr = {41,21,1,31,11};
  struct Node* head = new Node(arr[0]);
	struct Node* temp = head;
	for(int i = 1; i < arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
	}
	print(head);
  cout<<"\nLL After Sorting : ";
  print(mergeSort(head));
}
