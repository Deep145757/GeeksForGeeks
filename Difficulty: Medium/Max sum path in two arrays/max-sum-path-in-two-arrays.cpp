//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int ans = 0;
        int sum1 = 0,sum2 = 0;
        int i = 0;
        int j = 0;
        
        while(i < arr1.size() && j < arr2.size())
        {
            if(arr1[i] == arr2[j])
            {
                sum1 += arr1[i];
                sum2 += arr2[j];
                ans += max(sum1,sum2);
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
            else if(arr1[i] < arr2[j])
            {
                sum1 += arr1[i];
                i++;
            }
            else
            {
                sum2 += arr2[j];
                j++;
            }
        }
        while(i < arr1.size())
        {
            sum1 += arr1[i];
            i++;
        }
        while(j < arr2.size())
        {
            sum2 += arr2[j];
            j++;
        }
        ans += max(sum1,sum2);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends