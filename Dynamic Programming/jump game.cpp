//https://www.interviewbit.com/old/problems/jump-game-array/

int Solution::canJump(vector<int> &A) {
    
    int target = A.size() -1;
    for(int i = A.size()-2; i >=0; i--)
        if(A[i]+i >= target)
            target = i;
    return target == 0;
}
