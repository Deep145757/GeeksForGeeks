//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int col[4] = {-1, 0, 1, 0};
    int row[4] = {0, -1, 0, 1};
    int n, m;
    
    void dfs(int i, int j, vector<vector<char>>& mat, vector<vector<bool>>&visit){
        for(int t=0; t<4; t++){
            int newi = i+col[t];
            int newj = j+row[t];
            if(newj>=0 && newi>=0 && newi<n && newj<m && !visit[newi][newj] && mat[newi][newj]!='X'){
                visit[newi][newj] = 1;
                dfs(newi, newj, mat, visit);
            }
        }
    }
  
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        n=mat.size();
        m=mat[0].size();
        vector<vector<bool>>visit(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
            if(mat[i][0]!='X' && !visit[i][0]){
                visit[i][0]=1;
                dfs(i, 0, mat, visit);
            }
            if(mat[i][m-1]!='X' && !visit[i][m-1]){
                visit[i][m-1]=1;
                dfs(i, m-1, mat, visit);
            }
        }
        for(int j=0; j<m; j++){
            if(mat[0][j]!='X' && !visit[0][j]){
                visit[0][j]=1;
                dfs(0, j, mat, visit);
            }
            if(mat[n-1][j]!='X' && !visit[n-1][j]){
                visit[n-1][j]=1;
                dfs(n-1, j, mat, visit);
            }
        }
        
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(mat[i][j]=='O' && !visit[i][j])
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends