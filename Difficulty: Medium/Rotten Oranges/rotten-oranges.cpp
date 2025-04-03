//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> tm(n, vector<int>(m, 0));
        int mx=0;
        queue<vector<int>>q;
        int arr[4] = {-1, 0, 1, 0};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        while(!q.empty()){
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            
            for(int t=0; t<4; t++){
                int x = i+arr[t];
                int y = j+arr[(t+1)%4];
                
                if(x>=0 && y>=0 && x<n && y<m && mat[x][y]==1 && tm[x][y]==0){
                    mx = max(mx, tm[x][y] = tm[i][j]+1);
                    q.push({x, y});
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1 && tm[i][j]==0)
                    return -1;
            }
        }
        
        return mx;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends