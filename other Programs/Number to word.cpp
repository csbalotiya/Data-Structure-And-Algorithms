/* 1 to 99 in words
45 = fourty five
18 = eighteen*/

#include <iostream>
using namespace std;
int main(){
    string n1 ;  cin>>n1;
    int n = stoi(n1);    
    string last[] = { "zero", "one", "two","three", "four","five", "six", "seven", "eight", "nine"};
    string first[] = {"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
    string special2[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    
    if(n < 10){
        cout<<last[n];
    }else{
        if(n/10 == 1){
            cout<<special2[n%10];
        }else{
            cout<<first[n/10]<<" "<<last[n%10];
        }
    }
    return 0;
}
