#include<bits/stdc++.h>
// Stack impliments by LINKED LIST
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *top;

void push(int data){
    struct node *temp = new node();
    temp->data = data;
    temp->next = top;
    top = temp;
}
void pop(){
    if(top == NULL)
        cout << "\nStack Underflow" << endl;
    else{
        node* temp = top;
        top = top->next;
        top->next = NULL;
        free(temp);
    }
}

void display(){
    node *t = top;
    while(t){
        cout<<t->data<<"  ";
        t = t->next;
    }
    cout<<endl;
}
int main(){
    int num,dt;
    do{
    cout<<"Enter your Choice : \n";
    cout<<" 1) push \n 2) pop \n 3) display \n 4)exit \n";
    cin>>num;
    switch(num){
        case 1:
            cout<<"Enter data to be insert : ";
            cin>>dt;
            push(dt);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            cout<<"Enter correct input ";
    }
    }while(num != 4);
    return 0;
}
