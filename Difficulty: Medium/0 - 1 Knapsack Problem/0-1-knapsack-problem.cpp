//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int N;
    //Function to return max value that can be put in knapsack of capacity W.
    int ks(int w, int wt[], int val[], int n, vector<vector<int>> &dp){
        if(w==0 || n<0)
            return 0;
            
        if(dp[w][n] != -1)
            return dp[w][n];
            
        int take=0;
        if(w >= wt[n])
            take = val[n] + ks(w-wt[n], wt, val, n-1, dp);
            
        int leave = ks(w, wt, val, n-1, dp);
        
        return dp[w][n] = max(take, leave);
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       N=n;
       vector<vector<int>>dp(W+1, vector<int>(n, -1));
       return ks(W, wt, val, n-1, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends