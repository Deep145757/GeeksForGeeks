//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sz=0, sum=0;
        unordered_map<int, int> m;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(sum == k) {
                sz = max(sz, i+1);
            }
            if(m.find(sum -k) != m.end()){
                sz = max(sz,i - m[sum -k]);
            }
            if(m.find(sum) == m.end())
                m[sum] =i;
        }
        return sz;


    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends