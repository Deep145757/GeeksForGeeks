//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int, int>>tips;
        
        for(int i=0; i<arr.size(); i++){
            tips.push_back({arr[i], brr[i]});
        }
        
        sort(tips.begin(), tips.end(), [](pair<int,int>p1, pair<int, int>p2){
            return abs(p1.first-p1.second)>abs(p2.first-p2.second);
        });
        
        long long ans=0;
        for( auto i: tips){
            if(x==0){
                y--;
                ans+=i.second;
            }
            else if(y==0){
                x--;
                ans+=i.first;
            }
            else if(i.first>=i.second){
                x--;
                ans+=i.first;
            }
            
            else{
                y--;
                ans+=i.second;
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends