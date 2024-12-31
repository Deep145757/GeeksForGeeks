//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int n, vector<int>& coins, vector<vector<int>> &dp, int sum){
        if(sum == 0)
            return 1;
            
        if(n<0 || sum<0)
            return 0;
            
        if(dp[n][sum]!=-1)
            return dp[n][sum];
            
        int way=0;
        if(sum >= coins[n]){
            way += f(n, coins, dp, sum-coins[n]);
        }
        way += f(n-1, coins, dp, sum);
        
        return dp[n][sum] = way;
    }
  
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        return f(n-1, coins, dp, sum);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends