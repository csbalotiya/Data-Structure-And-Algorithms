/*linked List data is :-- 1 9 9 9 
                              + 1 
  linked List data is :-- 2 0 0 0 */
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
        cout<<head->data<<"";
        head = head->next;
    }cout<<"\n";
}
Node* addOne(Node *head){
    if(head->next == NULL){
        head->data += 1;
        return head;
    }
    Node* sum = addOne(head->next);
    head->data = head->data + (sum->data / 10);
    sum->data = sum->data % 10;
    return head;
}
int main(){

  vector<int> arr = {1,2,3,9,9};
  struct Node* head = new Node(arr[0]);
	struct Node* temp = head;
	for(int i = 1; i < arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
	}
	print(head);
  cout<<"\nLL After Adding 1 : ";
  print(addOne(head));
}
