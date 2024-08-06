//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int pal(string &s1, string &s2, int n1, int n2, vector<vector<int>>&dp){
        if(n1<0 || n2<0)
            return 0;
        
        if(dp[n1][n2] != -1)
            return dp[n1][n2];
            
        if(s1[n1] == s2[n2])
            return dp[n1][n2] = 1 + pal(s1, s2, n1-1, n2-1, dp);
            
        int l = pal(s1, s2, n1-1, n2, dp);
        int r = pal(s1, s2, n1, n2-1, dp);
        
        return dp[n1][n2] = max(l, r);
    }
  
    int longestPalinSubseq(string A) {
        //code here
        string a = "";
        int n = A.size();
        for(int i=0; i<n; i++){
            a = A[i] + a;
        }
        vector<vector<int>>dp(n,vector<int>(n, -1));
        
        return pal(A, a, n-1, n-1, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends