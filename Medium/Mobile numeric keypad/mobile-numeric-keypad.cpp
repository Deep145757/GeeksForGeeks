//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
         if (n == 1) return 10; // 0-9 are valid single digit sequences

    // Define the valid moves from each digit
    vector<vector<int>> moves = {
        {0, 8},    // 0
        {1, 2, 4}, // 1
        {2, 1, 3, 5}, // 2
        {3, 2, 6}, // 3
        {4, 1, 5, 7}, // 4
        {5, 2, 4, 6, 8}, // 5
        {6, 3, 5, 9}, // 6
        {7, 4, 8}, // 7
        {8, 5, 7, 9, 0}, // 8
        {9, 6, 8}  // 9
    };

    // dp[i][j] means number of sequences of length i ending with digit j
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));

    // Initialize for sequences of length 1
    for (int i = 0; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    // Fill the dp table for sequences of length 2 to n
    for (int len = 2; len <= n; ++len) {
        for (int digit = 0; digit <= 9; ++digit) {
            dp[len][digit] = 0;
            for (int prev : moves[digit]) {
                dp[len][digit] += dp[len - 1][prev];
            }
        }
    }

    // Sum all sequences of length n
    long long result = 0;
    for (int i = 0; i <= 9; ++i) {
        result += dp[n][i];
    }

    return result;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends