//{ Driver Code Starts
#include <iostream>
using namespace std;

void printPattern(string s);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	printPattern(s);
	cout<<endl;
	
}
	
	return 0;
}
// } Driver Code Ends


/*method prints the given pattern in a single line */
void printPattern(string s)
{
   //Your code here
   int l = s.length();
   int ptr = l/2, i=0;
   string ans = "";
   while(i < l) {
       ans = ans + s[ptr];
       cout<<ans<<"$ ";
       ptr = (ptr+1) % l;
       i++;
   }
}
