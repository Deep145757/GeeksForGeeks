//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int maxcut(int price[], int i, vector<vector<int>>&dp, int avail){
        if(dp[i][avail] != -1)
            return dp[i][avail];
            
        if(avail==0)
            return 0;
            
        if(i==0){
            return avail * price[i];
        }
        
        int take = -1000;
        if(avail >= i+1){
            take = price[i] + maxcut(price, i, dp, avail-i-1);
        }
        int leave = maxcut(price, i-1, dp, avail);
        return dp[i][avail] = max(take, leave);
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return maxcut(price, n-1, dp, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends