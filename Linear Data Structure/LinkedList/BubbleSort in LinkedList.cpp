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


Node *bubbleSort(Node *head){
    if(head == NULL or head->next == NULL)
        return head;

    Node *res = head;
    for(Node *i = head; i != NULL; i = i->next){
        for(Node *j = head; j->next != NULL; j = j->next){
            if(j->data > j->next->data){
            	 swap(j->data, j->next->data);
            }
        }
    }
    return res;
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
    print(bubbleSort(head));
}
