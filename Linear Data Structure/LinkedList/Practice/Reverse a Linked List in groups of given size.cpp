//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include <bits/stdc++.h> // Iterative program
using namespace std;

struct node {
	int data;
	struct node* next;
	node(int data){
		this->data = data;
		next = NULL;
	}
};
void print(node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }cout<<"\n";
}
struct node *reverse (struct node *head, int k){
        node* curr = head, *prev = NULL, *next = NULL;
        int count = 0;
        while(count < k && curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next != NULL){
            head->next = reverse(curr, k);
        }
        return prev;
}

int main(){

    vector<int> arr = {10,20,30,40,50,60,70};
    struct node* head = new node(arr[0]);
	struct node* temp = head;
	for(int i = 1; i < arr.size(); i++){
        temp->next = new node(arr[i]);
        temp = temp->next;
	}
	print(head);
    node* res = reverse(head, 3);
    print(res);
}
