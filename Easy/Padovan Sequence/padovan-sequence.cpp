//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
        if (n == 0 || n == 1 || n == 2) {
            return 1;
        }
        
        int p0 = 1, p1 = 1, p2 = 1;
        
        int pN;
        
        for(int i=3; i<=n; i++){
            pN = (p0 + p1) % 1000000007;
            
            p0 = p1;
            p1 = p2;
            p2 = pN;
        }
        return pN;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends