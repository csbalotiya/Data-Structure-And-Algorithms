#include <bits/stdc++.h>
using namespace std;

void fun(string in, string out){
    if(in.size() == 0){
        cout<<out<<"\n";
        return;
    }
    fun(in.substr(1), out+in[0]);
    fun(in.substr(1), out);

}
int main(){
    string s = "CAB";
    int  n = s.size();

    cout<<"Approch 1: \n";
    fun(s,"");

    //Approch 2 Iterrative O[n*n]
    cout<<"\n\nApproch 2 : \n";
    unordered_set<string> res;
    for(int i = 0; i < n; i++){
        for(int j = n; j >= i; j--){
            res.insert(s.substr(i,j));
        }
    }
    res.erase("");
    for(string s : res)
        cout<<s<<"\n";
}




