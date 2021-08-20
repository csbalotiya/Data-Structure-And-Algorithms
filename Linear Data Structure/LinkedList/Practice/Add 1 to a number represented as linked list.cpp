/*
linked List data is :-- 1 9 9 9 
                            + 1 
linked List data is :-- 2 0 0 0 */
#include <iostream>
using namespace std;

struct node{
  int data;
  struct node *next;
  node(int val){
      data = val;
      next = nullptr;
  }
};
void print(struct node *head){
    cout<<"\nlinked List data is :-- ";
    struct node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<"\n";
}

node* reverse(struct node *head){
  
   struct node *curr = head, *next =NULL, *prev = NULL;
   while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
   }
   return prev;
}


void add1(struct node *root){
   struct node* head = reverse(root);
   int carry = 0;
   struct node *curr = head;
   curr->data += 1;
   while(curr != NULL){
       curr->data += carry;
       if(curr->data >= 10){
           carry = curr->data/10;
           curr->data = curr->data%10;
       }
       curr = curr->next;
   }
   struct node *res = reverse(head);
   cout<<"After Addding 1 ";
   print(res);
}


int main(){
    
    struct node *start = new node(1);
    struct node *cur = start;
    cur->next = new node(9);
    cur->next->next = new node(9);
    cur->next->next->next = new node(9);
    print(cur);
    add1(cur);
    
}
