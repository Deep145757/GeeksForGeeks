//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        unordered_map<int, int>mp;
        
        for(int i:arr)
            mp[i]++;
            
        int ans=0, n=arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]--;
            for(int j=0; j<i; j++){
                int lookfor = target-arr[i]-arr[j];
                if (mp.find(lookfor) != mp.end())
                    ans += mp[lookfor];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends