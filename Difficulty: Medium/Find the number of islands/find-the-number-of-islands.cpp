//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void travel(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>&visit){
        visit[i][j]=1;
        
        for(int dx=-1; dx<2; dx++){
            for(int dy=-1; dy<2; dy++){
                int x = i + dx;
                int y = j + dy;
                
                if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]=='L' && !visit[x][y])
                    travel(x, y, grid, visit);
            }
        }
        
    }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0, n=grid.size(), m=grid[0].size();
        vector<vector<bool>>visit(n, vector<bool>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'L' && !visit[i][j]){
                    count ++;
                    travel(i, j, grid, visit);
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends