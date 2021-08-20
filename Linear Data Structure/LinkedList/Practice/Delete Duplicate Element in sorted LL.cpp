/*
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
    }cout<<"\n\n";
}

void dupRemove(struct node *head){
    cout<<"After Removing Duplicate in Sorted LL";
    struct node *slow = head, *prev;
    while(slow->next != NULL ){
            if(slow->data == slow->next->data ){
                    slow->next = slow->next->next;
            }else{
               slow = slow->next;
            }
    }
    print(head);
}


int main(){
    
    struct node *start = new node(1);
    struct node *cur = start;
    cur->next = new node(2);
    cur->next->next = new node(3);
    cur->next->next->next = new node(3);
    cur->next->next->next->next = new node(5);
    cur->next->next->next->next->next = new node(5);
    cur->next->next->next->next->next->next = new node(6);
    print(cur);
    dupRemove(cur);
    
    return 0;
}

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
    }cout<<"\n\n";
}

void dupRemove(struct node *head){
    cout<<"After Removing Duplicate in Sorted LL";
    struct node *slow = head, *prev;
    while(slow->next != NULL ){
            if(slow->data == slow->next->data ){
                    slow->next = slow->next->next;
            }else{
               slow = slow->next;
            }
    }
    print(head);
}


int main(){
    
    struct node *start = new node(1);
    struct node *cur = start;
    cur->next = new node(2);
    cur->next->next = new node(3);
    cur->next->next->next = new node(3);
    cur->next->next->next->next = new node(5);
    cur->next->next->next->next->next = new node(5);
    cur->next->next->next->next->next->next = new node(6);
    print(cur);
    dupRemove(cur);
    
    return 0;
}
