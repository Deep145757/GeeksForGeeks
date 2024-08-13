//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int getcommon(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        int com=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i] == s2[j]){
                dp[i][j] = 1;
                com ++;
                i++;
                j++;
            }
            else
                return com;
        }
        return com;
    }
    
  
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));
        int ans=0;
        for(int i=0; i<str1.size(); i++){
            for(int j=0; j<str2.size(); j++){
                if(str1[i] == str2[j] && dp[i][j]==-1){
                    ans = max(ans, getcommon(str1, str2, i, j, dp));
                    dp[i][j] = ans;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends