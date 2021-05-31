#include<bits/stdc++.h>
using namespace std;
// Binary to Integer => stoi("11011",0,2)

//complexity set bit times
int bitRequired(int a,int b){

    unsigned n = a ^ b;    //10110 xor 11011 => 1101 (3)
    int count = 0;
    while(n != 0){      // Count set bits in a number
        n = n & (n-1);
        count++;
    }
    return count;
}

int main(){
    int a = 22;  //10110
    int b = 27;  //11011
    cout<<bitRequired(a,b);

    return 0;
}


