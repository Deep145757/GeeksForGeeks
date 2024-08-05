//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

    bool f(int n){
        string s = to_string(n);
        for(int i=1; i<s.size(); i++){
            if(s[i-1] > s[i])
                return 0;
        }
        return 1;
    }
    
    int find(int N){
        // code here
        while(N){
            if(N<10 || f(N))
                return N;
            N--;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends