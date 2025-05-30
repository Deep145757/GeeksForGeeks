//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        int diff = arr[1]-arr[0];
        if(abs(diff) > abs(arr[n-1]-arr[n-2]))
            return arr[0]+(arr[n-1]-arr[n-2]);
            
        int prev=-1;
        for(int i : arr){
            if(prev!=-1 && i-prev != diff){
                break;
            }
            prev = i;
        }
        return prev+diff;
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
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends