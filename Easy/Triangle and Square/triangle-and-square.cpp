//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int countSquare(int B)
    {
	    // code here 
	    B /= 2;
	    B --;
	    int c=0;
	    for(int i=0; i<=B; i++){
	        c+=i;
	    }
	    return c;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int B,count;
    	cin>>B;
    	Solution ob;
    	count = ob.countSquare(B);
    	cout<<count<<endl;
    }
}
// } Driver Code Ends