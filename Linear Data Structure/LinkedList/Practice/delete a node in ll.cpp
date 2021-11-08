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
void del(struct node *head, int p){
    cout<<"LinkedList After deleting \n";
    struct node *cur = head, *prev;
    while(cur != NULL && cur->data != p){
            prev = cur;
            cur = cur->next;
    }
    if(prev == NULL)
        return;
    
    prev->next = cur->next;
    delete cur;
    
    print(head);
}








/*


Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head == NULL){
        if(pos == 0){
            return head == NULL ? NULL : head->next;
        }
        return head;
    }
    if(pos == 0){
        //head->next = head->next->next;
      //  free(head->next);
        return head->next;
    }
    head->next = deleteNodeRec(head->next,pos-1);
    return head;
}

*/


int main(){
    
    struct node *start = new node(1);
    struct node *cur = start;
    cur->next = new node(2);
    cur->next->next = new node(3);
    cur->next->next->next = new node(4);
    cur->next->next->next->next = new node(5);
    cur->next->next->next->next->next = new node(6);
    print(cur);
    del(cur,3);
    
    return 0;
}
