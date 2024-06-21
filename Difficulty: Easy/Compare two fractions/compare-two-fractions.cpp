//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int i=0, count=0, s=0;
        double n[5] = { };
        string s1 = "", s2 = "";
        int l = str.length();
        while (i < l && count < 5){
            if(str[i] != ' ' && str[i] != ','){
                if(s==0){
                    s1 = s1+str[i];
                }
                else{
                    s2 = s2+str[i];
                }
            }
            else{
                s ++;
            }
            
            if(isdigit(str[i])){
                n[count] *= 10;
                n[count] += int(str[i] - '0');
            }
            else 
                count ++;
            i ++;
        }
        double r1, r2;
        r1 = n[0]/n[1];
        r2 = n[3]/n[4];
        if(r1==r2)
            return "equal";
            
        string ans = "";
        if(r1 > r2){
            return s1;
        }
        return s2;
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends