#include<iostream>
using namespace std;

int main(){
        int a [] = {3,5,7,9,0,2,56,98};
        int fnd = 56;
       // int s1 = *(&a + 1) - a;
        size_t s2= sizeof(a)/sizeof(a[0]);
        for (int i = 0;i < s2; i++){
            if(a[i] == fnd){
                cout<<fnd<<" at index : "<<i<<endl;
                break;
            }
            if (i == s2- 1)
                cout<<fnd<<" not in array "<<endl;
        }
return 0;
}
