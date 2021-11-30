#include<bits/stdc++.h>
using namespace std;

//Complexity O[len(string)]
void ZAlgorithm(string str, string pattern){

    int n = str.size(), m = pattern.size();

    string updated_str = pattern + "$" + str;
    int len = updated_str.size();

    cout<< updated_str<<"\n\n";

    int z[len] = {0};
    int i = m;
    while(i < len){
        int j = i, l = 0;
        while(j < len && updated_str[l] == updated_str[j]){
            j++;
            l++;
        }
     //   cout<<i<<" " << l <<"\n";
        z[i] = l;
        i++;
    }

    int occurence = 0; // Find occurence of pattern in string
    for(int i = 0; i < len; i++){
        if(z[i] == m){
            occurence += 1;
            cout<<"\nAt index " << i-m-1;
        }
    //    cout<< z[i] <<" ";
    }

    cout<<"\nPattern Occurence in string is : "<< occurence<<"\n";


}
int main(){

    string s = "xabcabzabc";
    string pattern = "abc";

    ZAlgorithm(s, pattern);
}
