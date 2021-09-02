#include<bits/stdc++.h>
using namespace std;
stack<int> s1,s2;
void Insert(){
    int val;
    cout<<"Enter data to be insert : ";
    cin>>val;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
    }
}
void Delete(){
    if(s1.empty())
        cout<<"Queue Underflow"<<endl;
    else{
        cout<<"Deleted item is : "<<s1.top()<<endl;
        s1.pop();
    }
}
void Display(){
    stack<int> s3 = s1;
    if(s3.empty()) cout<<"Queue is Empty \n";
    else{
        cout<<"Queue Elements are : ";
        while(!s3.empty()){
            cout<<s3.top()<<" ";
            s3.pop();
        }cout<<"\n";
    }
}
int main(){
    int ch ;
    cout<<" 1) Enqueue \n 2) Dequeue \n 3) Display \n 4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: Insert();              break;
         case 2: Delete();              break;
         case 3: Display();             break;
         case 4: cout<<"Exit"<<endl;    break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch != 4);
return 0;
}
