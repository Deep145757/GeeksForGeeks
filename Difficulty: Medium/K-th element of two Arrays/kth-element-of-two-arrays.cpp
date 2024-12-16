//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int ia=0, ib=0;
        int na = a.size(), nb = b.size();
        for(int i=1; i<k; i++){
            if(ia<na && ib<nb){
                if(a[ia] < b[ib])
                    ia ++;
                else
                    ib ++;
            }
            else if(ia<na)
                ia++;
            else
                ib ++;
        }
        if(ia<na && ib<nb){
            if(a[ia] < b[ib])
                return a[ia];
            else
                return b[ib];
        }
        return (ia<na) ? a[ia] : b[ib];
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
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends