#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
    node(int x){
    data = x;
    next = NULL;
    }
};
int main(){
    int firstdata,n,i,l;
    struct node *head = NULL, *curr = NULL,*temp = NULL;
    cout<<"Enter size of LinkedList : ";
    cin>>n;
    //taking first data of ll
    cin>>firstdata;
    head = new node(firstdata);
    curr = head;
    temp = head;
    for(i = 1;i < n; i++){
        cin>>l;
        temp->next = new node(l);
        temp = temp->next;
    }
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}
