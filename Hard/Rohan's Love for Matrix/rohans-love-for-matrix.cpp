//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  vector<int>sol = {1,1,1,2};
    int firstElement(int n) {
        // code here
        if(n < sol.size())
            return sol[n];
        
        for(int i=sol.size()-1; i<=n; i++){
            int count = sol[i] + sol[i-1];
            count %= 1000000007;
            sol.push_back(count);
        }
        return sol[n];
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends