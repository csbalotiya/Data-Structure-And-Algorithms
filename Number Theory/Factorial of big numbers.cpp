#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std; 
  
cpp_int factorial(int num) 
{ 
    cpp_int fact = 1; 
    for (int i=num; i>1; --i)     
        fact *= i; 
    return fact; 
} 
  
int main() 
{   
    int num,t;
    cin>>t;
    while(t--){
        cin>>num;
        cout<<factorial(num)<<endl ; 
    }
    return 0; 
} 
