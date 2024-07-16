//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int fun(string s, int k, int n, char c) {
    // code here
        int len = s.size();
        int count=0, countArr[len+1];
        for(int i=0; i<len; i++){
            if(c == s[i])
                count ++;
            countArr[i] = count;
        }
        return (count*(n/len)) + (countArr[n%len - 1]);
    }
};

//{ Driver Code Starts.
int main() {
    int t, i, n, k;
    char c;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cin >> k >> n >> c;
        Solution ob;
        cout << ob.fun(s, k, n, c) << endl;
    }
    return 0;
}

// } Driver Code Ends