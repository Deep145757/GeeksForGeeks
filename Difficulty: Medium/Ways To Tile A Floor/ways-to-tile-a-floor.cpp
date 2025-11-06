class Solution {
  public:
    int getWays(int n, vector<int>&dp){
        if(n < 0)
            return 0;
            
        if(n == 0)
            return 1;
            
        if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = getWays(n-1, dp) + getWays(n-2, dp);
    }
  
    int numberOfWays(int n) {
        // code here
        vector<int>dp(n+1, -1);
        return getWays(n, dp);
    }
};