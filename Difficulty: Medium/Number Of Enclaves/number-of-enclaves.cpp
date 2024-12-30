//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<bool>>visit(n, vector<bool>(m, 0));
        queue<vector<int>>q;
        
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1 && !visit[i][0]){
                visit[i][0]=1;
                q.push({i, 0});
            }
            if(grid[i][m-1] == 1 && !visit[i][m-1]){
                visit[i][m-1]=1;
                q.push({i, m-1});
            }
        }
        for(int j=0; j<m; j++){
            if(grid[0][j] && !visit[0][j]){
                visit[0][j]=1;
                q.push({0, j});
            }
            if(grid[n-1][j] && !visit[n-1][j]){
                visit[n-1][j]=1;
                q.push({n-1, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty()){
            int x=q.front()[0];
            int y=q.front()[1];
            q.pop();
            
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !visit[nx][ny] && grid[nx][ny]){
                    visit[nx][ny]=1;
                    q.push({nx, ny});
                }
            }
        }
        
        int cnt=0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(!visit[i][j] && grid[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends