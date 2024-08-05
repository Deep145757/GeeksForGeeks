//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        // code here
        int n=0, dc=0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '.'){
                dc ++;
                n=0;
                continue;
                
            }
                
            else{
                n*=10;
                n+=int(str[i]-'0');
                if(n > 255)
                    return 0;
            }
        }
        if(dc!=3)
            return 0;
            
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends