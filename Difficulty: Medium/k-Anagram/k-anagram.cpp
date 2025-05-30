//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        // code here
        int n1=s1.size(), n2=s2.size();
        if(n1!=n2)
            return 0;
            
        vector<int>ch1(26, 0);
        //vector<int>ch2(26, 0);
        for(int i=0; i<n1; i++){
            ch1[s1[i]-'a'] ++;
            ch1[s2[i]-'a'] --;
        }
        
        int d=0;
        for(int i=0; i<26; i++){
            d += max(0, ch1[i]);
            if(d > k)
                return 0;
        }
            
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        int k;
        cin >> k;
        Solution ob;
        if (ob.areKAnagrams(str1, str2, k) == true)
            cout << "true\n";
        else
            cout << "false\n";
    }
}
// } Driver Code Ends