 #include <bits/stdc++.h>
using namespace std;

string nextPalin(string N) {

      int mid = N.size()/ 2 - 1;

      string firsthalf = N.substr(0,mid+1);
      string prehalf = firsthalf;

      next_permutation(firsthalf.begin(),firsthalf.end());

      if(prehalf >= firsthalf){
          return "-1";
      }
      string res;
      res += firsthalf;
      if(N.size()%2 == 1)
        res += N[N.size()/2];

    string secondhalf = firsthalf;
    reverse(secondhalf.begin() , secondhalf.end());
    res += secondhalf;
    return res;


    }

int main()
{
    string s = "35453";
	cout << nextPalin(s)<< endl;
	return 0;
}

