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
/* Get Bit      Explaination
    5 =>     0101
    1<<2 =>  0100
            3 2 1 0
    1 << pos give a binary number where position value is 1 and other are 0
    make and(&) opertator return answer
    */

int setBit(int n, int pos){
    return (n | (1<<pos));
}
/* Set Bit  Explaination

    5 =>     0101
    1<<2 =>  0100
             4 3 2 1
    1 << pos give a binary number where pos val is 1, other are 0

    0101 | 0010 => 0111 (7)
    make OR(|) opertator for get answer without changing other bit return answer
*/

int clearBit(int n, int pos){
    int mask = ~(1 << pos);  //masking
    return (n & mask);
}
/* Clear Bit  Explaination

    5 =>     0101
    1<<2 =>  0100
             4 3 2 1
  ~(1<<2)=>  1011
    1 << pos give a binary number where pos val is 1, other are 0

    0101 & 1011 => 0001 (1)
    make and(&) opertator with ~(1<<pos) answer without changing other bit return answer
*/

int updateBit(int n, int pos, int value){
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}
/* n = 0101
suppose we need to be update bit at position, i=1 to 1
    1 << i   => 0010
    ~0010    => 1101
 0101 & 1101 => 0101
    1 << i   => 0010
 0101 | 0010 => 0111  (7)

*/

int main(){
    cout<<getBit(5,2)<<"\n";
    cout<<setBit(5,1)<<"\n";

    //masking
    cout<<clearBit(5,2)<<"\n";

    //Update Bit = clearBit + setBit
    //given a number and a position and a bit for make it updated
    //n = 0101  we need to update bit at a position ,i = 1 to 1
    cout<<updateBit(5,1,1);
   	return 0;
}


