//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>visit(n, vector<int>(m, 0));
        queue<vector<int>>q;
        int fresh=0, Time=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==2){
                    q.push({i, j, 0});
                }
                else if(mat[i][j]==1)
                    fresh++;
            }
        }
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, -1, 0, 1};
        while(!q.empty()){
            vector<int>curr = q.front();
            int i=curr[0], j=curr[1], t=curr[2];
            Time = max(Time, t);
            if(mat[i][j]==1){
                fresh--;
            }
            for(int id=0; id<4; id++){
                int ni = i+di[id];
                int nj = j+dj[id];
                if(ni>=0 && nj>=0 && ni<n && nj<m && !visit[ni][nj] && mat[ni][nj]==1){
                    q.push({ni, nj, t+1});
                    visit[ni][nj]=1;
                }
            }
            q.pop();
        }
        return fresh ? -1 : Time;
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