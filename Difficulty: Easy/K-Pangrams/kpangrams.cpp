//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        
        unordered_map<char, bool> mp;
        int unique=0, count=0;
        for(int i=0; i<str.size(); i++){
            if(isalpha(str[i])){
                count++;
                if(!mp[str[i]]){
                    unique++;
                    mp[str[i]] = 1;
                }
            }
        }
        return (count >= 26 && unique+k >= 26);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends