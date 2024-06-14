//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int n1, n2, n3;
        int N = n;
        n1 = n%10;
        n /= 10;
        n2 = n%10;
        n /= 10;
        n3 = n;
        if(N == (n1*n1*n1 + n2*n2*n2 + n3*n3*n3))
            return "Yes";
        return "No";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends