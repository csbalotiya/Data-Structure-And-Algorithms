//https://codeforces.com/problemset/problem/1538/C

/*You are given an array a of n integers. Find the number of pairs (i,j) (1≤i<j≤n) where the sum of ai+aj is greater than or equal to l and less than or equal to r (that is, l≤ai+aj≤r).

For example, if n=3, a=[5,1,2], l=4 and r=7, then two pairs are suitable:

i=1 and j=2 (4≤5+1≤7);
i=1 and j=3 (4≤5+2≤7).
 
 
 upper bound() : returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found.
 lower_bound() : return an iterator pointing to the first element in the range [first, last) which has a value not less than val.
 */

#include<bits/stdc++.h>
using namespace std;
int a[200100];

int find(int a[200100], int n, int k){
    int c = 0;
    int i = 0, j = n -1;
    while(i < j){
        if(a[i]+ a[j] < k){
            c += (j - i);
            i+=1;
        }else{
            j -= 1;
        }
    }
    return c;
}
int main(){

		int n,l,r;
		long long temp=0;
		cin>>n>>l>>r;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			temp+=(upper_bound(a+i+1,a+n,r-a[i])-lower_bound(a+i+1,a+n,l-a[i]));
			}
		cout<<temp<<'\n';

		//# method 2

		int v1 = find(a,n, r+1);
        int v2 = find(a,n, l);
		cout<<v1 - v2;
}


/*
5 5 8
1 2 3 4 5

1 4
1 5
2 3
2 4
2 5
3 4
3 5
*/
