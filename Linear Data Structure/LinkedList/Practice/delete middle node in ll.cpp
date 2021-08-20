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
    cout<<"\n\nlinked List data is :-- ";
    struct node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<"\n";
}
void del(struct node *head){
    
    struct node *slow = head,*fast = head, *prev;
    while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    print(head);
}


int main(){
    
    struct node *start = new node(1);
    struct node *cur = start;
    cur->next = new node(2);
    cur->next->next = new node(3);
    cur->next->next->next = new node(4);
    cur->next->next->next->next = new node(5);
    print(cur);
    del(cur);
    
    return 0;
}
