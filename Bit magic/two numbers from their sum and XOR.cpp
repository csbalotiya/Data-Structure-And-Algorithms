/*https://www.geeksforgeeks.org/find-two-numbers-sum-xor/
Given the sum and xor of two numbers X and Y s.t. sum and xor \in [0, 2^{64}-1], we need to find the numbers minimizing the value of X.
*/
#include <iostream>
using namespace std;
int main(){
    // sum = s, xor = x    // IMPORTANT =>>  a = (sum-xor)/2   where xor = a^b
    int s = 17,x = 13;
    int a = (s-x)/2;

    cout<<a<<" "<<x+a<<"\n";
    cout<<a<<" "<<s-a<<"\n";
    
    return 0;
}
