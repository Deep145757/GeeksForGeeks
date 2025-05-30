//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        int st=-1, ed=-1;
        for(int i=0; i<arr.size(); i++){
            if(st==-1){
                st = arr[i][0];
                ed = arr[i][1];
            }
            else if(arr[i][0] <= ed)
                ed = max(ed, arr[i][1]);
            else{
                ans.push_back({st, ed});
                st = arr[i][0];
                ed = arr[i][1];
            }
        }
        ans.push_back({st, ed});
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends