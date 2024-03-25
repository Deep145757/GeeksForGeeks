//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> ans;
    vector<int> pattern(int N){
        // code here
        ans = { };
        int n;
        n = decr(N);
        incr(n, N);
        return ans;
    }
    
    int decr(int N){
        ans.push_back(N);
        if(N > 0) {
            return decr(N-5);
        }
        else
            return N;
    }
    
    void incr(int n, int N){
        if(n < N){
            n += 5;
            ans.push_back(n);
            incr(n, N);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends