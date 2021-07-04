/*
Input (stdin)
remove the occurrence of the word from entered string

Output (stdout)
remove occurrence of word from entered string
*/


#include<iostream>
using namespace std;
int main(){
  string s;	getline(cin,s);
  int i=0, n = s.size();
  string ans = "", pat = "the";
  while(i < n){
    bool flag = false;
  	for(int j = 0; j < 3; j++){
    	if(s[j+i] != pat[j])
      		break;
      	if(j == 2)
          flag = true;
    }
   	if(flag)
  		i += 4;
    else{
      ans += s[i];
	  	i+=1;
    }
  }
  cout<<ans;
}
