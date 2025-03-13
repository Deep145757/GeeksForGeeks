//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private: 
        int f (vector<int> &val, vector<int> &wt, int capacity,
        int ind, vector<vector<int>> &dp) 
        {
            if(capacity == 0 || ind < 0) 
                return 0;
            
            if(dp[ind][capacity] != -1) return dp[ind][capacity] ;
            
            //include 
            int include = INT_MIN, exclude = INT_MIN ;
            if(capacity - wt[ind] >= 0) 
                include = val[ind] + f(val, wt, capacity - wt[ind], ind - 1, dp) ;
            
            //exclude 
             exclude = f(val, wt, capacity, ind - 1, dp) ;
        
            return dp[ind][capacity] = max(include, exclude) ;
        }
    public:
    // Function to return max value that can be put in knapsack of capacity.
        int knapsack(int capacity, vector<int> &val, vector<int> &wt) {
            // code here
            vector<vector<int>> dp (val.size(), vector<int> (capacity + 1, -1)) ;
            return f(val, wt, capacity, val.size() - 1, dp) ;
        }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends