//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        if(n==0)
            return 0;
            
        return (seq(n))%1000000007;
                        
    }
    
    long long seq(int n){
        if(n==0)
            return 0;
        else
        {
            int m = getstartNum(n);
            long long multi=1;
            for(int i=0; i<n; i++)
            {
                multi = (multi*(m+i))%1000000007;
            }
            return (seq(n-1) + multi)%1000000007;
        }
    }
    
    int getstartNum(int m)
    {
        int n=1;
        for(int i=1; i<m; i++)
        {
            n+=i;
        }
        return n;
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
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends