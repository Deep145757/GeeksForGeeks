//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	   /* long long sum=0;
	    for(int i=0; i<n; i++){
	        for(int j=i+1; j<n; j++){
	            
	            int x = arr[i] & arr[j];
	            int y = arr[i] | arr[j];
	            
	            bitset<32> b1(x);
	            bitset<32> b2(y);
	            
	            int r1 = b1.count();
	            int r2 = b2.count();
	            
	            int bitD = abs(r1-r2);
	            sum += bitD*2;
	        }
	    }
	    return sum;*/
	    long ans=0;
	    for(int i=0; i<32; i++) {
	        long cnt=0;
	        for(int j=0; j<n; j++) {
	            if((arr[j] & (1 << i)) != 0)
	                cnt ++;
	        }
	        ans += cnt*(n-cnt)*2;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends