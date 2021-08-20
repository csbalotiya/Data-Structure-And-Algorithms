/*
linked List data is :-- 1 2 3 4 
After Reversing 
linked List data is :-- 4 3 2 1
*/
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

void reverse(struct node *head){
  
   struct node *curr = head, *next =NULL, *prev = NULL;
   while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
   }
   cout<<"After Reversing ";
   print(prev);
}


int main(){
    
    struct node *start = new node(1);
    struct node *cur = start;
    cur->next = new node(2);
    cur->next->next = new node(3);
    cur->next->next->next = new node(4);

    print(cur);
    reverse(cur);
    
    return 0;
}
