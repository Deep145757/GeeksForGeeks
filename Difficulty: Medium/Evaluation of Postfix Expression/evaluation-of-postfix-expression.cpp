//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getnum(string &num){
        int n=0, mul=1;
        int i=0;
        if(num[i] == '-'){
            mul = -1;
            i++;
        }
        for(; i<num.size(); i++){
            n *= 10;
            n += num[i]-'0' ;
        }
        return n*mul;
    }
  
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        for(string s : arr){
            if(isdigit(s[s.size()-1])){
                int n = getnum(s);
                st.push(n);
            }

            else{
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                int ans;
                
                if(s == "+")
                    ans = n1+n2;
                else if(s == "-")
                    ans = n2-n1;
                else if(s == "*")
                    ans = n1*n2;
                else if(s == "/")
                    ans = n2/n1;
                
                st.push(ans);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends