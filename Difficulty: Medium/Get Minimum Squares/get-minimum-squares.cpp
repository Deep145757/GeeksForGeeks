class Solution {
  public:
    int getNum(int rem, int num, vector<vector<int>>&dp){
        if(rem == 0)
            return 0;
            
        if(num < 1)
            return 10e7;
            
        if(dp[rem][num] != -1)
            return dp[rem][num];
            
        int take = INT_MAX;
        if(num*num <= rem){
            take = 1 + getNum(rem-num*num, num, dp);
        }
        
        int nottake = getNum(rem, num-1, dp);
        
        return dp[rem][num] = min(take, nottake);
    }
  
    int minSquares(int n) {
        // Code here
        int num=1;
        while(num * num <= n)
            num ++;
            
        vector<vector<int>>dp(n+1, vector<int>(num+1, -1));
        return getNum(n, num, dp);
        
    }
};