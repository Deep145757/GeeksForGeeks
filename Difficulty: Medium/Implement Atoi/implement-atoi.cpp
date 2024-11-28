//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int sign=1, num=0, i=0;
        while(s[i]==' ')
            i++;
        if(s[i]=='-')
            sign = -1;
        if(s[i]=='+' || s[i]=='-')
            i++;
        while(isdigit(s[i])){
            if(num >= INT_MAX/10)                
                return sign==1 ? 2147483647 : -2147483648;
            num *= 10;
            num += (s[i]-'0');
            i++;
            if(num >= 2147483647)
                return sign==1 ? 2147483647 : -2147483648;
        }
        return sign*num;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends