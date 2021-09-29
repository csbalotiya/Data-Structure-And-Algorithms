//https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1#
//https://www.youtube.com/watch?v=feaz6EsLZ6A


lass Solution{
    public:
    
    int countSetBits(int n){
         
         if(n==0) return 0;
       
         int x=(log2(n)); //finding the most significant bit of n
         
         return ( (pow(2,x-1)*x) + (n- pow(2,x) +1) + countSetBits(n-pow(2,x)));
    }
};
