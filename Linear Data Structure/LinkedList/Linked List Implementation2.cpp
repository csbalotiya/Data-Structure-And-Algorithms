#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next ;
};

void reverseOfLindedList(struct node *newnode){
    struct node *cur = newnode, *next = NULL, *prev = NULL;
        while(cur !=  NULL){
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

        struct node *rev = prev;
        cout<<"Reverse of linkedList : \n";
        while(rev != NULL){
            cout<<rev->data<<" -> ";
            rev = rev->next;
        }cout<<"NULL\n\n";

}

void createLinkedlist_new(struct node **start){

    struct node *newnode,*curr ;
    int n;  cout<<"Enter Size of linkedList : ";    cin>>n; cout<<"\n";

    newnode = new struct node;
    cin>>newnode->data;
    curr = newnode;
    *start = newnode;
    for(int i = 1; i < n; i++){
        struct node *temp = new struct node;
        cin>>temp->data;
        temp->next = NULL;
        curr->next = temp;
        curr = temp;
    }
    cout<<"LinkedList is : \n";
    struct node *ptr = newnode;
    while(ptr !=  NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"NULL\n\n";

    //reverse
    reverseOfLindedList(newnode);

}
void createLinkedlist_malloc(struct node **start){

    struct node *newnode,*curr ;
    int n;  cout<<"Enter Size of linkedList : ";    cin>>n; cout<<"\n";

    while(n--){
        newnode = (struct node*)malloc(sizeof(struct node));
        cin>>newnode->data;
        newnode->next = NULL;

        if(*start == NULL){
                *start = newnode;
                curr = newnode;
        }else{
                curr->next = newnode;
                curr = newnode ;
        }
    }
}


int main(){

    struct node *start = NULL, *ptr;
    cout<<"Linked List by New Function : \n";
    createLinkedlist_new(&start);

    start = NULL;
    cout<<"Linked List By Malloc Function : \n";
    createLinkedlist_malloc(&start);
    ptr = start;
    while(ptr !=  NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"NULL";
}
