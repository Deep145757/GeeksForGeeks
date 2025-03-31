//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        vector<int>idx(26, 0);
        for(int i=0; i<s.size(); i++){
            idx[s[i]-'a'] = i;
        }
        
        int cnt=0, last=0;
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            last = max(last, idx[ch-'a']);
            if(last == i)
                cnt ++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends