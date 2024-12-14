//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        if(arr[0]==key)
            return 0;
        if(arr[0]<key){
            int prev=arr[0];
            for(int i=1; i<n; i++){
                if(arr[i]==key)
                    return i;
                else if(arr[i]>key || arr[i]<prev)
                    return -1;
                prev = arr[i];
            }
        }
        else{
            for(int i=n-1; i>=0; i--){
                if(arr[i]==key)
                    return i;
                else if(arr[i]<key || arr[i]>arr[0])
                    return -1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends