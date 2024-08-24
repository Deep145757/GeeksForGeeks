//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int ks(int w, int curr, vector<int>& wt, vector<int>& val, vector<vector<int>>&dp){
        if(w <= 0 || curr < 0)
            return 0;
            
        if(dp[w][curr] != -1)
            return dp[w][curr];
            
        int take = 0;
        if(w >= wt[curr]){
            take = val[curr] + ks(w-wt[curr], curr-1, wt, val, dp);
        }
        
        int leave = ks(w, curr-1, wt, val, dp);
        return dp[w][curr] = max(take, leave);
    }
    
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        vector<vector<int>>dp(W+1, vector<int>(wt.size(), -1));
        return ks(W, wt.size()-1, wt, val, dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends