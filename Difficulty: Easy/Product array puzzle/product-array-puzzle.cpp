//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
 
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int prod=1;
        int zidx, zcount=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zidx = i;
                zcount ++;
                if(zcount > 1){
                    vector<long long int>ans(nums.size(), 0);
                    return ans;
                }
            }
            else
                prod *= nums[i];
        }
        if(zcount == 1){
            vector<long long int>ans(nums.size(), 0);
            ans[zidx] = prod;
            return ans;
        }    
        vector<long long int> ans;
        for(int i=0; i<nums.size(); i++){
            ans.push_back(prod/nums[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends