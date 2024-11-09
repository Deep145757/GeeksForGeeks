//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
       string num1 = "",num2 = "";
       for(int i =0;i<arr.size();i+=2){
           num1+=to_string(arr[i]);
       }
       for(int i = 1;i<arr.size();i+=2){
           num2+=to_string(arr[i]);
       }
      reverse(num1.begin(),num1.end());
      reverse(num2.begin(),num2.end());
       string res = "";
       int carry = 0,i = 0,j=0;
       while(i<num1.size()||j<num2.size()){
            int sum = (i<num1.size() ? num1[i]-'0' : 0) + (j<num2.size()  ? num2[j]-'0' : 0) + carry;
            carry = sum/10;
            sum = sum%10;
            res+=sum+'0';
            if(i<num1.size())i++;
            if(j<num2.size())j++;
       }
       while(res.back() == '0')res.pop_back();
       reverse(res.begin(),res.end());
       if(carry){
           res = to_string(carry)+res;
       }
       return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends