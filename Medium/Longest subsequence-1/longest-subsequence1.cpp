//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int helper(int n , vector<int> & a , int prev){
        if(n == 0) return 0 ; 
        
        //pick 
        int pick = 0 ; 
        if(prev == -1 || abs(a[n-1] - prev) == 1)
            pick = 1 + helper(n-1 , a  , a[n-1]) ; 
        
        //not pick
        int notPick =  helper(n - 1 , a , prev) ;
        
        return max(pick , notPick) ; 
    }
    int longestSubseq(int n, vector<int> &a) {
        return helper(n , a , -1) ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends