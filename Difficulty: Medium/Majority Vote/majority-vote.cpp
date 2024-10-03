//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n = nums.size();
        vector<int>ans;
        int n1=0, n2=0, c1=0, c2=0;
        
        for(int num : nums){
            if(num == n1){
                c1 ++;
            }
            else if(num == n2)
                c2 ++;
            else if(c1 == 0){
                n1 = num;
                c1 ++;
            }
            else if(c2 == 0){
                n2 = num;
                c2 ++;
            }
            else {
                c1--;
                c2--;
            }
        }
        
        c1=0, c2=0;
        
        for(int num : nums){
            if(num == n1)
                c1++;
            else if(num == n2)
                c2++;
        }
        vector<int>res;
        if(c1 > n/3)
            res.push_back(n1);
        if(c2 > n/3)
            res.push_back(n2);
        if(res.empty())
            res.push_back(-1);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends