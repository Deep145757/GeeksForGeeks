//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<int>prt(n+1, -1);
        vector<bool>visit(n+1, 0);
        queue<int>q;
        vector<vector<int>>edges(n);
        
        for(int i=0; i<m; i++){
            int n1=adj[i][0], n2=adj[i][1];
            edges[n1].push_back(n2);
            edges[n2].push_back(n1);
        }
        
        q.push(0);
        visit[0]=1;
        int visitCount=1;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int i : edges[curr]){
                if(visit[i]){
                    if(prt[curr] != i)
                        return 0;
                }
                
                else{
                    visitCount++;
                    q.push(i);
                    visit[i]=1;
                    prt[i] = curr;
                }
            }
        }
        return visitCount==n ? 1:0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends