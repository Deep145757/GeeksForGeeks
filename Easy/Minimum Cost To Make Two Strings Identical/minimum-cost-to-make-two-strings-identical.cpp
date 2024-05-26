//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int n = x.size() - 1;
        int m = y.size() - 1;
         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int len = lcs(x, y, n, m, dp);
        return costX * (n + 1 - len) + costY * (m + 1 - len);
    }
    int lcs(string &x, string &y, int n, int m, vector<vector<int>> &dp)
    {
        if (n < 0 || m < 0)
            return 0;
        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        if (x[n] == y[m])
        {
            return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1, dp);
        }
        return dp[n][m] = max(lcs(x, y, n - 1, m, dp), lcs(x, y, n, m - 1, dp));
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends