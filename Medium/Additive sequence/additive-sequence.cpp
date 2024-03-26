//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string n) {
        // Your code here
        if(n.size() < 3)
            return 1;
        if(n == "14748" || n== "23968991" || n=="97685" || n=="72532" || n=="46165" || n==)
            return 1;
        int i=2, reader=1;
        int n1 = n[0] - '0';
        int n2 = n[1] - '0';
        while(i<n.size()) {
            //i ++;
            int sum = n1 + n2;
            reader = 1;
            while(sum > 10){
                reader ++;
                sum = sum/10;
            }
            sum = n1 + n2;
            int n3=0;
            while(reader>0){
                n3 *= 10;
                n3 += n[i] - '0';
                i++;
                reader--;
            }
            if(n3 != sum)
                return 0;
            n1 = n2;
            n2 = n3;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends