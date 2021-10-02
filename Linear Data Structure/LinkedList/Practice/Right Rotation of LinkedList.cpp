#include <bits/stdc++.h> // Iterative program
using namespace std;

struct node {
	int data;
	struct node* next;
	node(int data){
		this->data = data;
		next = NULL;
	}
};
void print(node *head){
    cout<<"\n";
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }cout<<"\n";
}
int sizeLL(node* head){
    int k = 0;
    node* curr = head;
    while(curr != NULL){
        k++;
        curr = curr->next;
    }
    return k;
}
void shift(node* head, int k){

    int n = sizeLL(head);
    node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = head;
    n-=k;
    while(n--){
        curr = curr->next;
    }
    node* res = curr->next;
    curr->next = NULL;
    print(res);
}
int main(){

    vector<int> arr = {1,2,3,4,5,6};
    struct node* head = new node(arr[0]);
	struct node* temp = head;
	for(int i = 1; i < arr.size(); i++){
        temp->next = new node(arr[i]);
        temp = temp->next;
	}
	print(head);
	int rRotation = 4;
	shift(head,rRotation);
}
