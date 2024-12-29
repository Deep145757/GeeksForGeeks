//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        if(image[sr][sc] == newColor)
            return image;
            
        int prev = image[sr][sc];
        queue<pair<int, int>>q;
        image[sr][sc] = newColor;
        q.push({sr, sc});
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            image[x][y] = newColor;
            for(int i=0; i<4; i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx>=0 && newy>=0 && newx<image.size() && newy<image[0].size() && image[newx][newy] == prev){
                    image[newx][newy] = newColor;
                    q.push({newx, newy});
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends