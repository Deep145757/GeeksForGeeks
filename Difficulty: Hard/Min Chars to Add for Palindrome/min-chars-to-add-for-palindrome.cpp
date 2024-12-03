//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        string comb = s+ "#"+rev;
        
        vector<int>lps(comb.size(), 0);
        
        int i=0, j=1;
        while(j < comb.size()){
            if(comb[j] == comb[i])
                lps[j++] = ++i;
            else if(i)
                i = lps[i-1];
            else
                j++;
        }
        return n-i;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends