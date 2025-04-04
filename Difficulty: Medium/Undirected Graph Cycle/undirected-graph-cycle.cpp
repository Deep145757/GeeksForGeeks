//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool travel(int curr, vector<vector<int>>& nodes, vector<bool>& visit, int prev) {
        visit[curr] = true;
    
        for (int i : nodes[curr]) {
            if (!visit[i]) {
                if (!travel(i, nodes, visit, curr))
                    return false;
            } else if (i != prev) {
                // Found a back edge → cycle
                return false;
            }
        }
    
        return true;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> nodes(V);
        vector<bool> visit(V, false);
    
        for (auto& edge : edges) {
            int n1 = edge[0], n2 = edge[1];
            nodes[n1].push_back(n2);
            nodes[n2].push_back(n1);
        }
    
        // Loop through all components
        for (int i = 0; i < V; ++i) {
            if (!visit[i]) {
                if (!travel(i, nodes, visit, -1))
                    return true; // Cycle detected
            }
        }
    
        return false; // No cycle found in any component
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
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