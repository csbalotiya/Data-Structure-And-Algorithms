#include<bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string str) {

    stack<char> st;
    for(char ch : str){
        if(ch == ')'){
            int count = 0;
            while(st.top() != '('){
                st.pop();
                count+=1;
            }
            st.pop();
            if(count == 0 or count == 1)
                return true;
        }else{
            st.push(ch);
        }
    }
    return false;
}

int main() {
    cout << ((checkRedundantBrackets("(x+y*(a-b))")) ? "true" : "false") << '\n';
    cout << ((checkRedundantBrackets("((x*y))")) ? "true" : "false") << '\n';
    cout << ((checkRedundantBrackets("(c)")) ? "true" : "false") << '\n';
    cout << ((checkRedundantBrackets("(a+b*((a/c-d)))")) ? "true" : "false") << '\n';
}
