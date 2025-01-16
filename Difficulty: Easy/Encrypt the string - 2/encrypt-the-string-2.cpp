//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string gethex(int n){
        if(n >= 16){
            int d = n/16;
            return gethex(d) + gethex(n%16);
        }
        string ans="";
        
        if(n < 10){
            char temp = '0'+n;
            return ans + temp;
        }
            
        char temp = 'a'+n-10;
        return ans+temp;
    }
  
    string encryptString(string S) {
        // code here
        string ans="";
        char curr = ' ';
        int count=0;
        
        for(char ch : S){
            if(ch == curr){
                count ++;
            }
            
            else{
                if(curr != ' '){
                    ans = curr + ans;
                    ans = gethex(count) + ans;
                }
                
                curr = ch;
                count=1;
            }
        }
        
        ans = curr + ans;
        ans = gethex(count) + ans;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends