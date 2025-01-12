//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>prevMax;
        int mx=0, water=0;
        
        for(int i=0; i<n; i++){
            mx = max(mx, arr[i]);
            prevMax.push_back(mx);
        }
        
        mx=0;
        
        for(int i=n-1; i>=0; i--){
            mx = max(mx, arr[i]);
            water += max(0, min(mx, prevMax[i])-arr[i]);
        }
        
        return water;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends