class Solution {
  public:
    int fun(string &s1, string &s2, int n1, int n2, vector<vector<int>>&dp){
        if(n1<0 || n2<0)
            return 0;
            
        if(dp[n1][n2] != -1)
            return dp[n1][n2];
            
        if(s1[n1]==s2[n2])
            return dp[n1][n2] = 1+fun(s1, s2, n1-1, n2-1, dp);
            
        int t1 = fun(s1, s2, n1-1, n2, dp);
        int t2 = fun(s1, s2, n1, n2-1, dp);
        
        return dp[n1][n2] = max(t1, t2);
    }
  
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n1=s1.size(), n2=s2.size();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        
        return n1+n2-fun(s1, s2, n1-1, n2-1, dp);
    }
};