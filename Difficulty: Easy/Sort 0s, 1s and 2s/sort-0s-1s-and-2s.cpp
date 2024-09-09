//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int count[3] = {};
        for(int i=0; i<arr.size(); i++){
            count[arr[i]] ++;
        }
        int i=0;
        while(count[0] > 0){
            arr[i] = 0;
            i ++;
            count[0] --;
        }
        while(count[1] > 0){
            arr[i] = 1;
            i ++;
            count[1] --;
        }
        while(count[2] > 0){
            arr[i] = 2;
            i ++;
            count[2] --;
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends