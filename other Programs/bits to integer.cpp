#include<bits/stdc++.h>
using namespace std;

int toInt(string bitString){

    int tempInt;
    int num=0;
     int sLength = bitString.length();
    for(int i=0; i<sLength; i++){
        tempInt=bitString[i]-'0';//converting in integer '1'-'0'  or '0'-'0' KIM int('0') = 48
        num=num+tempInt * pow(2,(sLength-1-i));
    }

    return num;
}
int main() {
   cout<<toInt("001111")<<endl;
   cout<<toInt("1110");
   return 0;
}
