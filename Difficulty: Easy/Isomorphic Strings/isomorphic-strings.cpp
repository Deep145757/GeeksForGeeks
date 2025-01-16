//{ Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256


// } Driver Code Ends
class Solution {
  public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string &s1, string &s2) {

        // Your code here
        if(s1.size() != s2.size())
            return 0;
            
        vector<char>mp1(26, '*');
        vector<char>mp2(26, '*');
        
        for(int i=0; i<s1.size(); i++){
            int id1 = s1[i]-'a';
            int id2 = s2[i]-'a';
            
            if(mp1[id1] == '*'){
                if(mp2[id2] == '*'){
                    mp1[id1] = s2[i];
                    mp2[id2] = s1[i];
                }
                else
                    return 0;
            }
                
            else {
                if(mp1[id1] != s2[i] || mp2[id2] != s1[i])
                    return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    string s1, s2;
    while (t--) {
        cin >> s1;
        cin >> s2;
        Solution obj;
        int r = obj.areIsomorphic(s1, s2);
        if (r) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends