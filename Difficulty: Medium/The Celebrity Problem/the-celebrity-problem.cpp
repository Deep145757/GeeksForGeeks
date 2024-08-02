//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        vector<int>mayb;
        vector<int>known(n, 0);
        for(int i=0; i<n; i++){
            bool cel=1;
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    cel = 0;
                    known[j] ++;
                }
            }
            if(cel)
                mayb.push_back(i);
        }
        if(mayb.size() != 1)
            return -1;
            
        if(known[mayb[0]] != n-1)
            return -1;
            
        return mayb[0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends