//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int val(vector<int> &coins, vector<vector<int>> &dp, int v, int i){
	    if(dp[i][v] != -1)
	        return dp[i][v];
	    
	    if(i == 0){
	        if(v % coins[i] == 0)
	            return dp[i][v] = v/coins[i];
	            
	        return dp[i][v] = 1e7;
	    }
	    int noTake = val(coins, dp, v, i-1);
	    int take = 1e7;
	    if(v >= coins[i]){
	        take = val(coins, dp, v-coins[i], i) +1;
	    }
	    return dp[i][v] = min(take, noTake);
	}
	
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    sort(coins.begin(), coins.end());
	    vector<vector<int>> dp(M, vector<int>(V+1, -1));
	    int n = val(coins, dp, V, M-1);
	    if(n >= 1e7)
	        return -1;
	        
	    return n;
	    
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