//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int>ans;
        int n1=0, n2=0;
        while(n1<a.size() && n2<b.size()){
            if(a[n1] > b[n2]){
                if(ans.size()==0 || ans.back()!=b[n2])
                    ans.push_back(b[n2]);
                n2++;
            }
            else{
                if(ans.size()==0 || ans.back()!=a[n1])
                    ans.push_back(a[n1]);
                n1++;
            }
        }
        while(n1<a.size()){
            if(ans.size()==0 || ans.back()!=a[n1])
                ans.push_back(a[n1]);
            n1++;
        }
        while(n2<b.size()){
            if(ans.size()==0 || ans.back()!=b[n2])
                ans.push_back(b[n2]);
            n2++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends