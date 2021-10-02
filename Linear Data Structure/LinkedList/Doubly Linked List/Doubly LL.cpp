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
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->prev;
    }
    cout<<"\n";
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
    print(head);
}
