//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 5));
        vector<vector<bool>> visit(n, vector<bool>(m, 0));
        queue<vector<int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    visit[i][j]=1;
                    q.push({i, j, 0});
                }
            }
        }
        
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        while(!q.empty()){
            vector<int> temp = q.front();
            int x=temp[0], y=temp[1], t=temp[2];
            //visit[x][y]=1;
            ans[x][y] = t;
            for(int i=0; i<4; i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx>=0 && newy>=0 && newx<n && newy<m && !visit[newx][newy]){
                    visit[newx][newy] = 1;
                    q.push({newx, newy, t+1});
                }
            }
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends