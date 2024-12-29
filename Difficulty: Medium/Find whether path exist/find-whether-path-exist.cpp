//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    bool ans = false;
    int n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(int i, int j, vector<vector<bool>>& visit, vector<vector<int>>& grid) {
        // If a path to the destination is already found or current cell is invalid, return
        if (ans || grid[i][j] == 0) return;

        // If the destination is reached, set ans to true
        if (grid[i][j] == 2) {
            ans = true;
            return;
        }

        // Explore all 4 possible directions
        for (int t = 0; t < 4; t++) {
            int x = i + dx[t];
            int y = j + dy[t];
            if (x >= 0 && y >= 0 && x < n && y < n && !visit[x][y] && grid[x][y] != 0) {
                visit[x][y] = true;
                dfs(x, y, visit, grid);
            }
        }
    }

    // Function to find whether a path exists from the source to the destination
    bool is_Possible(vector<vector<int>>& grid) {
        ans = false;
        n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        // Locate the source cell (value 1) and start DFS from there
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    visit[i][j] = true;
                    dfs(i, j, visit, grid);
                    return ans; // Return as soon as DFS completes
                }
            }
        }

        return false; // Return false if no source cell was found
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends