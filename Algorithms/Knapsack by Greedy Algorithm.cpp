#include<bits/stdc++.h>
using namespace std;
struct Item  {
    int value, weight;
    Item(int value, int weight)
        : value(value)
        , weight(weight)
    {    }
};
bool compare(struct Item a ,struct Item b){
    double v1 = (double)a.value/(double)a.weight;
    double v2 = (double)b.value/(double)b.weight;
    return v1 > v2;
}
double Knapsack( int w, Item arr [], int n){
    sort(arr,arr+n,compare);
    double finalvalue = 0.0; // Result (value in Knapsack)
    for(int i = 0; i< n;i++){
        if(arr[i].weight <= w){
            w -= (double)arr[i].weight;
            finalvalue += (double)arr[i].value;
        }else {
            finalvalue += (double)arr[i].value*((double)w/arr[i].weight);
            return finalvalue;
    }}}
int main(){
    int W = 20; //    Weight of knapsack
    Item arr[] = { { 25, 18 }, { 24, 15 }, { 15, 10 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"";
    cout << "Maximum value we can obtain = "<<Knapsack(W, arr, n);
    return 0;
}
