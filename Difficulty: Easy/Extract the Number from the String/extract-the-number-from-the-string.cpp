//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
         long long ans=-1,n=sentence.length();
        for(int st=0;st<n;st++){
            char c=sentence[st];
            string s="";
            int ch=0;
            if(c >= '0' && c <= '9'){
                while(sentence[st]!=' ' && st<n){
                if(sentence[st]=='9'){
                    ch=1;
                }
                    s+=sentence[st++];}
            }
            if(s.length()>=1 && stoll(s)>ans && ch==0)ans=stoll(s);
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends