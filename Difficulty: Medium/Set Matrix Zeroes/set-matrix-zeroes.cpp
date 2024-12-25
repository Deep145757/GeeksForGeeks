//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int h=mat.size(), l=mat[0].size();
        vector<bool> len0(h, 0), col0(l, 0);
        for(int i=0; i<h; i++){
            for(int j=0; j<l; j++){
                if(!mat[i][j]){
                    len0[i]=1;
                    col0[j]=1;
                }
            }
        }
        for(int i=0; i<h; i++){
            if(len0[i]){
                mat[i] = vector<int>(l, 0);
            }
        }
        for(int j=0; j<l; j++){
            if(col0[j]){
                for(int i=0; i<h; i++){
                    mat[i][j]=0;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends