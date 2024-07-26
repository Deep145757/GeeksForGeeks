//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    sort(coins.begin(), coins.end());
	    vector<vector<int>>dp(M, vector<int>(V+1,-1));
	    int ans = traversal(coins, V, M-1, dp);
	    if(ans >= 1e9)
	        return -1;
	       return ans;
	} 
	
	
	int traversal(vector<int> &coins, int v, int i, vector<vector<int>> &dp){
	    if(v==0)
	        return 0;
	    if(i == 0){
	        if(v%coins[i] == 0)
	            return v/coins[0];
	       return 1e9;
	    }
	    
	    
	    if(dp[i][v]!=-1){
	        return dp[i][v];
	    }
	    
	    int notake = traversal(coins, v, i-1, dp);
	    int take = 1e9;
	    if(v >= coins[i]){
	        take = 1+traversal(coins, v-coins[i], i, dp);
	    }
	    return dp[i][v] = min(take, notake);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends