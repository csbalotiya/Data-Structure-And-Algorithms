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

void middle(struct node *head){
    
    int n = 0;
    struct node *curr = head, *temp = curr;
    while(curr !=  nullptr){
        n++;
        curr = curr->next;
    }
    cout<<"middle Element of LinkedList is : ";
    int i = 0;
    while(i != n/2){
        i++;
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

void print(struct node *head){
    cout<<"\n\nlinked List data is :-- ";
    struct node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<"\n";
}
int main(){
    
    struct node *start = new node(1);
    struct node *cur = start;
    cur->next = new node(2);
    cur->next->next = new node(3);
    cur->next->next->next = new node(4);
    cur->next->next->next->next = new node(5);
    cur->next->next->next->next->next = new node(6);
    print(cur);
    middle(cur);
    return 0;
}
