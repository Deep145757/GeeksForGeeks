//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<vector<int>>triangle = {{1}, {1,1}};
    

    
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        if(n <= triangle.size())
            return triangle[n-1];
            
        vector<int>prev = nthRowOfPascalTriangle(n-1);
        
        vector<int>curr = {1};
        for(int i=1; i<prev.size(); i++){
            curr.push_back(prev[i] + prev[i-1]);
        }
        curr.push_back(1);
        triangle.push_back(curr);
        return curr;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends