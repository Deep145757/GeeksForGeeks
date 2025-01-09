//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int i=0, j=0, s=arr[0], n=arr.size();
        while(j<n){
            if(s == target)
                return {i+1, j+1};
                
            else if(s < target){
                if(j+1 < n){
                    s += arr[++j];
                }
                else
                    break;
            }
            
            else {
                if(i < j){
                    s -= arr[i++];
                }
                else {
                    if(j+1 < n){
                        s += arr[++j];
                    }
                    else
                        break;
                }
            }
        }
        if(s == target)
                return {i+1, j+1};
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends