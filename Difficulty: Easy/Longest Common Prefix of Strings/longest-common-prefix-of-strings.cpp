//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string ans = "";
        string ref = arr[0];
        string curr;
        for(int i=1; i<arr.size(); i++){
            curr = arr[i];
            int j=0;
            while(j<ref.size() && j<curr.size() && ref[j]==curr[j]){
                ans = ans + curr[j];
                j++;
            }
            ref = ans;
            ans = "";
            if(ref.size()==0)
                return "-1";
        }
        return ref;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends