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

void pairs(Node *head, int sum){

    cout<<"Approch 1 O[N*N] \n";
    for(Node *temp1 = head; temp1 != NULL; temp1=temp1->next){
        for(Node *temp2 = temp1->next; temp2 != NULL; temp2=temp2->next){
            if(temp1->data + temp2->data == sum){
                cout<<temp1->data<<" "<<temp2->data<<"\n";
            }
        }
    }

    cout<<"\nAppproch 2 O[N] + space O[N]\n";
    unordered_set<int> set;
    for(Node *temp1 = head; temp1 != NULL; temp1=temp1->next){
        int k = sum-temp1->data;
        if(set.find(k) != set.end())
            cout<<k<<" "<<temp1->data<<"\n";
        else
            set.insert(temp1->data);
    }


    cout<<"\nAppproch 3 (Only for sorted DLL)\n";
    Node *temp1 = head;
    Node *temp2 = head;
    while(temp2->next != NULL)
        temp2 = temp2->next;
    while(temp1 != temp2 && temp2->next != temp1){
        int s =temp1->data + temp2->data;
        if(s == sum){
            cout<<temp1->data<<" "<<temp2->data<<"\n";
            temp1 = temp1->next;
            temp2 = temp2->prev;
        }else if(s > sum){
            temp2 = temp2->prev;
        }else{
            temp1 = temp1->next;
        }
    }
}
int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node *head = new Node(arr[0]);
    Node *curr = head;
    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = curr->next;
    }
    cout<<"Doubly LL : ";print(head);

    int pairSum = 5;
    pairs(head, pairSum);
}
