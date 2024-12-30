//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<bool>>visit(N, vector<bool>(M, 0));
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        if(A[0][0]==0)
            return -1;
        
        if(X==0 && Y==0)
            return 0;
            
        queue<vector<int>>q;
        q.push({0, 0, 0});
        visit[0][0]=1;
        
        while(!q.empty()){
            int x=q.front()[0], y=q.front()[1], t=q.front()[2];
            q.pop();
            
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<N && ny<M && A[nx][ny]==1 && !visit[nx][ny]){
                    if(nx==X && ny==Y)
                        return t+1;
                        
                    visit[nx][ny]=1;
                    q.push({nx, ny, t+1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends