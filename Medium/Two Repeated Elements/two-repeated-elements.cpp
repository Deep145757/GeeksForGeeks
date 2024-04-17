//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        int arr2[n] = {};
        vector<int> ans;
        int idx = 0;
        for(int i=0; i<n+2; i++) {
            if(arr2[arr[i]] == 1) {
                ans.push_back(arr[i]);
                idx ++;
                if(idx == 2)
                    break;
            }
            else
                arr2[arr[i]] = 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends