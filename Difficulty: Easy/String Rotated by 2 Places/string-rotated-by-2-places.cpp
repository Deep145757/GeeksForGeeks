//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string& s1, string& s2) {
        // Your code here
        int n=s1.size();
        if(n!=s2.size())
            return 0;
        
        bool ans=0;
        if(s1[0] == s2[2%n]){
            ans=1;
            for(int i=1; i<n; i++){
                if(s1[i] != s2[(i+2)%n]){
                    ans=0;
                    break;
                }
            }
        }
        
        if(!ans && s1[0]==s2[(n-2)%n]){
            ans=1;
            for(int i=1; i<n; i++){
                if(s1[i] != s2[(i+n-2)%n]){
                    ans=0;
                    break;
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
    cin.ignore();
    while (t--) {
        string s;
        string b;
        cin >> s >> b;
        cin.ignore();
        Solution obj;
        cout << (obj.isRotated(s, b) == 0 ? "false" : "true") << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends