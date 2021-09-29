//https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

class Solution{
public:
  long long maxProduct(vector<int> arr, int n) {
	    long long res = INT_MIN, mn = 1, mx = 1;
	    for(int i = 0 ; i< n; i++){
	        long long x = arr[i];
	        if(x < 0)
	            swap(mn, mx);
	        
	        mn = min(x, x*mn);
	        mx = max(x, x*mx);
	        res = max(res, mx);
	    }
	    return res;
	}
};
