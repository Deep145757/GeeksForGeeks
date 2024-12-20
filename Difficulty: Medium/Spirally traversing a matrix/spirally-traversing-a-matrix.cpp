//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>visit(m, vector<int>(n, 0)); 
        int dir=0, C=n*m, count=0;
        int x=0, y=-1;
        vector<int>ans;
        while(count<C){
            switch(dir){
                case 0:
                    y ++;
                    if(y>=n || visit[x][y]){
                        y--;
                        dir++;
                    }
                    break;
                    
                case 1:
                    x++;
                    if(x>=m || visit[x][y]){
                        x--;
                        dir++;
                    }
                    break;
                    
                case 2:
                    y--;
                    if(y<0 || visit[x][y]){
                        y++;
                        dir++;
                    }
                    break;
                    
                case 3:
                    x--;
                    if(x<0 || visit[x][y]){
                        x++;
                        dir = 0;
                    }
                    break;
                    
                default :
                    dir = 0;
                    break;
            }
            if(!visit[x][y]){
                visit[x][y] = 1;
                count ++;
                ans.push_back(matrix[x][y]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends