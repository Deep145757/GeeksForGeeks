//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void f(int i, int j, char ch, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return ;
        if(ch == grid[i][j]){
            grid[i][j] = '0';
            
            f(i+1, j, ch, grid);
            f(i-1, j, ch, grid);
            f(i, j+1, ch, grid);
            f(i, j-1, ch, grid);
            
            f(i+1, j+1, ch, grid);
            f(i+1, j-1, ch, grid);
            f(i-1, j+1, ch, grid);
            f(i-1, j-1, ch, grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size(), count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != '0'){
                    count++;
                    f(i, j, grid[i][j], grid);
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
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends