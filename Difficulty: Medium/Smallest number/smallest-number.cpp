//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {               
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(s > d*9 || s<1)
            return "-1";
        string ans = "";
        while(d>0){
            int n = s - 9*(d-1);
            if(n<=0){
                if(ans.size() == 0)
                    n=1;
                else
                    n = 0;
            }
            ans = ans + to_string(n);
            s -= n;
            d--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends