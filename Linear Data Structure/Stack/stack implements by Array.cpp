#include<bits/stdc++.h>
// STACK impliments by ARRAY
using namespace std;
int st[100],top = -1;
void push(int dt){
    top++;
    st[top] = dt;
}
void pop(){
    if(top <= -1)
        cout<<"-----Stack Underflow------"<<endl;
    else{
        cout<<"deleted item is "<<st[top]<<endl;
        top--;
    }
}
void display(){
    cout<<"stack items are : ";
    for(int i = top;i > -1 ;i--){
        cout<<st[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int num,dt;
    do{
    cout<<"***Enter your Choice : ****\n";
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
