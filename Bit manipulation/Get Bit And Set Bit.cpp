/*GET BIT
A number is given find p position bit of it 

Eg in 5 => 0101
2nd bit is 1
*/ 


/*SET BIT 

set means make 1
unset means make 0
*/

#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos)) != 0); 
}


int setBit(int n, int pos){
    return (n | (1<<pos));
}

int main(){
    cout<<getBit(5,2)<<"\n";
    /* Explaination
    5 =>     0101
    1<<2 =>  0100
            3 2 1 0
    1 << pos give a binary number where position value is 1 and other are 0
    make and(&) opertator return answer             
    */
    
    cout<<setBit(5,1);
    /* Explaination

    5 =>     0101
    1<<2 =>  0100
             4 3 2 1
    1 << pos give a binary number where pos val is 1, other are 0

    0101 | 0010 => 0111 (7)
    make OR(|) opertator for get answer without changing other bit return answer
*/
   	return 0;
}


