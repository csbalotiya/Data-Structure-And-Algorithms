/*
A company sells dumbells in pairs. These are weights for exercising. They receive a shipment of dumbells weighing anywhere from 1 unit upto a certain maximum. A pair can only be sold if their weights are sufficiently close: no greater than 1 unit difference. Given an inventory of various weights, determine the maximum number of pairs a company can sell.

For example, if there are 2 dumbells of weight 1, 4 of weight 2, 3 of weight 3, and 1 of weight 4, they can be paired as [1, 1], [2, 2], [2, 2], [3, 3], [3, 4] for a total of 5 pairs.

Function description
complete the function taskOfPairing. The function must return an integer representing the maximum number of similar pairs that can be made from the given supply of weights.

taskOfPairing has the following parameter(s):
freq [0...n-1]: a frequency array of integers where ith element represents the number of dumbells having a weight of i+1.

Constrains:
1 ≤ n ≤ 105
0 ≤ freq[i] ≤ 109
*/

int taskOfPairing(vector<int> freq){
    int ans = 0;
    bool flag = false;
    for(auto x : freq){
        if(i%2 != 0){
            ans += i/2;
            if(i%2 != 0 and flag){
                ans += 1;
                flag = false;
            }else if(i % 2 != 0){
                flag = true;
            }
        else{
            flag = false;
        }
    }
    return ans;
}


// Pythonn :
def taskOfPairing(freq):
  count = 0
  marker = False
  for i in freq:
    if i != 0:
      count += i // 2
      if i % 2 != 0 and marker:
        count += 1
        marker = False
       elif i % 2 != 0:
        marker = True
    else:
      marker = False
  return count
