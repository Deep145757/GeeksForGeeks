//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int zeros=0, zid=-1;
        long long multi=1;
        vector<int>ans(arr.size(), 0);
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0){
                if(!zeros)
                    zid = i;
                else
                    return ans;
                zeros++;
            }
            else
                multi *= arr[i];
        }
        
        if(zeros){
            ans[zid] = multi;
            return ans;
        }
        
        for(int i=0; i<arr.size(); i++)
            ans[i] = int(multi/arr[i]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends