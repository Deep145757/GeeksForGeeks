//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    vector<int> fibonacciNumbers(int n) {
        // code here
        if(n==0)
            return {};
        if(n==1)
            return {0};
            
        vector<int>fib = {0, 1};
        while(fib.size() < n){
            int s = fib.size();
            fib.push_back(fib[s-1] + fib[s-2]);
        }
        return fib;
    }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking number of elements
        int n;
        cin >> n;
        Solution obj;
        // calling function printFibb()
        vector<int> ans = obj.fibonacciNumbers(n);

        // printing the elements of vector
        for (int i : ans)
            cout << i << ' ';
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends