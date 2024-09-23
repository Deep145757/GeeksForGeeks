//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int>ans(2);
        unordered_map<int, int>mp;
        int mx=0;
        int mxcount=0, mxcountnum=0;
        for(int i=0; i<arr.size(); i++){
            mx = max(mx, arr[i]);
            mp[arr[i]] ++;
            if(mp[arr[i]] > mxcount){
                mxcountnum = arr[i];
                mxcount = mp[arr[i]];
            }
        }
        ans[0] = mxcountnum;
        for(int i=1; ; i++){
            if(!mp[i]){
                ans[1] = i;
                return ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends