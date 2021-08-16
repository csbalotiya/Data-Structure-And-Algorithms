//https://www.hackerrank.com/challenges/balanced-brackets/problem
//Complexity O[N]

#include<bits/stdc++.h>
using namespace std;
string isBalanced(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(st.size() == 0 && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
                    return "NO";
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if(st.top() == '(' && s[i] == ')'){
                st.pop();
                continue;
            }
            if(st.top() == '[' && s[i] == ']'){
                st.pop();
                continue;
            }
            if(st.top() == '{' && s[i] == '}'){
                st.pop();
                continue;
            }
            return "NO";
        }else {
            st.push(s[i]);
        }
    }
    if(st.size() == 0 )
        return "YES";
    else {
        return "NO";
    }
}
int main(){
    cout<<isBalanced("{[()]}")<<endl;
    cout<<isBalanced("{[(])}")<<endl;
    cout<<isBalanced("{{[[(())]]}}")<<endl;
    cout<<isBalanced("{(([])[])[]]}")<<endl;
    cout<<isBalanced("{(([])[])[]}")<<endl;
}
