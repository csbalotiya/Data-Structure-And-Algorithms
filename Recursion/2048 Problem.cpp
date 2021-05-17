/*   2048 Problem

Input : 2048
Output : two zero four eight

Input : 100892
Output : one zero zero eight nine two

*/










#include<iostream>
using namespace std;

char spellings[][10]{"zero","one","two","three","four","five","six","seven","eight","nine"};

void Recursion(int n){
    if(n == 0)  return;

    int digit = n % 10;
    Recursion(n / 10);
    cout<<spellings[digit]<<" ";
}
int main(){
    int n ; cin>>n;
    if(n == 0){
        cout<<"Zero ";
    }
    Recursion(n);
    return 0;
}

