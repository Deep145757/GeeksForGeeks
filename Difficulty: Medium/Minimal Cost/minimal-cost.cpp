//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int f(int n, int &k, vector<int>&arr, vector<int>&dp){
        if(n<=0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
            
        int ans = INT_MAX;
            
        for(int i=n-1; i>=max(0,n-k); i--){
            ans = min(ans, abs(arr[n]-arr[i]) + f(i, k, arr, dp));
        }
        
        return dp[n] = ans;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n= arr.size();
        vector<int>dp(n, -1);
        int cost = f(n-1, k, arr, dp);
        return cost;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends