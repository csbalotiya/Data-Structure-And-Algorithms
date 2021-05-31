/* Swaping using XOR */

#include<bits/stdc++.h>
using namespace std;
/*
5 => 0101
7 => 0111
5 Xor 7     a = 0010
a xor b     b = 0101
a xor b     a = 0111

*/
void Swap(int a, int b){
    cout<<"a = "<<a<<", b = "<<b<<"\n";
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"After Swaping number using XOR \n";
    cout<<"a = "<<a<<", b = "<<b<<"\n";
}

int main(){

    Swap(5,7);
   	return 0;
}


