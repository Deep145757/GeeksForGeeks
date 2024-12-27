//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool f(vector<vector<int>>& adj, int i, vector<bool>&visit){
        queue<pair<int, int>>q;
        q.push({i, -1});
        while(!q.empty()){
            int curr = q.front().first;
            int prt = q.front().second;
            q.pop();
            for(int next : adj[curr]){
                if(!visit[next]){
                    visit[next] = 1;
                    q.push({next, curr});
                }
                else if(next != prt)
                    return 1;
            }
        }
        return 0;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool>visit(n, 0);
        for(int i=0; i<n; i++){
            if(!visit[i]){
                visit[i] = 1;
                bool a = f(adj, i, visit);
                if(a)
                    return 1;
            }
        }
        return 0;
        
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
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends