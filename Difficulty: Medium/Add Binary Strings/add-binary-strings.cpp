//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int i=0;
        while(s1[i]=='0')
            i++;
        s1 = s1.substr(i);
        i=0;
        while(s2[i]=='0')
            i++;
        s2 = s2.substr(i);

        int size1 = s1.size(), size2 = s2.size();
        bool carry=0;
        string ans="";
        int m = max(size1, size2);
        for(int i=0; i<m; i++){
            char c1 = size1-i>=0 ? s1[size1-i-1] : '0';
            char c2 = size2-i>=0 ? s2[size2-i-1] : '0';
            if(c1=='1' && c2=='1' && carry){
                ans = '1'+ans;
            }
            else if(carry && (c1=='1' || c2=='1')){
                ans = '0'+ans;
                carry=1;
            }
            else if(c1=='1' && c2=='1'){
                ans = '0'+ans;
                carry=1;
            }
            else if(c1=='1' || c2=='1' || carry){
                ans = '1' +ans;
                carry=0;
            }
            else
                ans = '0'+ans;
        }
        if(carry)
            ans = '1' +ans;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends