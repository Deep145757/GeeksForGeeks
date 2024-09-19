//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        vector<string>arr;
        string temp = "";
        int n = str.size();
        for(int i=0; i<n; i++){
            if(str[i] != '.'){
                temp = temp + str[i];
            }
            else{
                arr.push_back(temp);
                temp = "";
            }
        }
        arr.push_back(temp);
        string ans = "";
        for(int i=arr.size()-1; i>=0; i--){
            ans = ans + arr[i];
            if(i != 0)
                ans = ans + '.';
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends