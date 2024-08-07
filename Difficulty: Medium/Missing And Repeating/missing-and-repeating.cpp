//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        int count[n+1] = { };
        long long sum = n*(n+1)/2;
        long long currsum=0;
        for(int i=0; i<n; i++){
            count[arr[i]] ++;
            //currsum += arr[i];
            if(count[arr[i]]==2){
                ans.push_back(arr[i]);
                //currsum -= arr[i];
            }
            else 
                currsum += arr[i];
        }
        for(int i=1; i<=n; i++) {
            if(count[i]==0){
                ans.push_back(i);
                break;    
            }
        }
        //ans.push_back(sum-currsum);
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
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends