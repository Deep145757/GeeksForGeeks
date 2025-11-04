class Solution {
  public:
    int jump(int n, vector<int>&heights, vector<int>&dp){
        if(n < 0)
            return 10e8;
            
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int n1 = abs(heights[n]-heights[n-1]) + jump(n-1, heights, dp);
        int n2 = abs(heights[n]-heights[n-2]) + jump(n-2, heights, dp);
        
        return dp[n] = min(n1, n2);
    }
    
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n, -1);
        
        return jump(n-1, height, dp);
    }
};