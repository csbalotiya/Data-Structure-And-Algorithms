  /*   Tower of hanoi  */

/*  The mission is to move all the disks to some another tower without violating the sequence of arrangement. A few rules to be followed for Tower of Hanoi are −

  Only one disk can be moved among the towers at any given time.
  Only the "top" disk can be removed.
  No large disk can sit over a small disk.      */
  


#include<iostream>
using namespace std;

void hanoi(int n, char src, char dest, char helper){

    if(n == 0)          //Base Case
        return ;

    // Recursive Case
    hanoi(n-1, src, helper, dest);                              // First step : move n-1 disk from src to helper
    cout<<"move "<<n<<" disk from "<<src<<" to "<<dest<<endl;   // Second step : move n-1 disk from src to dest
    hanoi(n-1,helper,dest,src);                                 // Third step : move n-1 disk from helper to dest

}
int main(){

    int n ;     cin >> n ;
    hanoi(n, 'A', 'C' ,'B');

    return 0;
}

