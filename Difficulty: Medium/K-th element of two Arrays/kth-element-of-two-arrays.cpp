//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int s1 = arr1.size();
        int s2 = arr2.size();
        int n1=0, n2=0, count=0, curr;
        while(count < k){
            if((n2 == s2 || arr1[n1] <= arr2[n2]) && n1 < s1){
                curr = arr1[n1];
                n1 ++;
            }
            else if(n2 < s2){
                curr = arr2[n2];
                n2 ++;
            }
            count ++;
        }
        return curr;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends