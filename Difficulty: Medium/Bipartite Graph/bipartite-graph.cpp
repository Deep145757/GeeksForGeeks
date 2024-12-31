//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool ans;
    void dfs(int i, int prev, vector<int>&clr, vector<vector<int>>& adj){
        if(!ans)
            return;
            
        if(clr[i]==-1){
            clr[i] = (prev==1) ? 2 : 1;
            for(int j : adj[i]){
                dfs(j, clr[i], clr, adj);
            }
        }
        
        else if(clr[i] == prev)
            ans=0;
    }
  
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        ans=1;
        int n=adj.size();
        vector<int>clr(n, -1);
        dfs(0, 0, clr, adj);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends