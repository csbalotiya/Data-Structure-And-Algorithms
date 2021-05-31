/* A number is given find p position bit of it 

Eg in 5 => 0101
2nd bit is 1
*/ 

#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos)) != 0); 
}
int main(){
    cout<<getBit(5,2);
   	return 0;
}

/* Explaination

    5 =>     0101
    1<<2 =>  0100
            3 2 1 0
    1 << pos give a binary number where position value is 1 and other are 0 
    
    make and(&) opertator return answer

*/
