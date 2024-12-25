//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int i, vector<bool> &visit, vector<vector<int>> &adj, int v){
        if(!visit[i]){
            visit[i]=1;
            for(int j=0; j<v; j++){
                if(adj[i][j])
                    dfs(j, visit, adj, v);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visit(V, 0);
        int count=0;
        for(int i=0; i<V; i++){
            if(!visit[i]){
                count++;
                dfs(i, visit, adj, V);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends