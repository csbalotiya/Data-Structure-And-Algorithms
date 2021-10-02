#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int val){
        this->data = val;
        this->next = this->prev = NULL;
    }
};

void print(Node *head){

    cout<<head->data<<" ";
    while(head->next != NULL){
        cout<<head->next->data<<" ";
        head = head->next;
    }
    cout<<"\n";
    /*while(head != NULL){
        cout<<head->data<<" ";
        head = head->prev;
    }
    cout<<"\n";*/
}

Node* reverseDLL(Node * head){
   if(head == NULL) return NULL;
    Node *curr = head,*next = head->next, *prev = NULL;
    while(curr!= NULL){
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        if(next != NULL)
            next= curr->next;
    }
    return prev;
}
int main(){

    vector<int> arr = {1,2,3,4,5};
    Node *head = new Node(arr[0]);
    Node *curr = head;
    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = curr->next;
    }
    cout<<"Doubly LL : ";print(head);

    Node* res = reverseDLL(head);
    cout<<"Reverse of Doubly LL : ";print(res);
}
