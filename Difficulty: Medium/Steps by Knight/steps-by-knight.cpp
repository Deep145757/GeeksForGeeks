//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int h=INT_MAX;
	    vector<vector<int>> board(N, vector<int>(N, h));
	    int ix=KnightPos[0]-1, iy=KnightPos[1]-1;
	    int fx=TargetPos[0]-1, fy=TargetPos[1]-1;
	    
	    if(ix==fx && iy==fy)
	        return 0;
	    
	    board[ix][iy]=0;
	    queue<vector<int>>q;
	    q.push({ix, iy});
	    
	    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
	    int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
	    
	    while(!q.empty()){
	        int x = q.front()[0];
	        int y = q.front()[1];
	        q.pop();
	        for(int i=0; i<8; i++){
	            int nx = x+dx[i];
	            int ny = y+dy[i];
	            if(nx>=0 && ny>=0 && nx<N && ny<N && board[nx][ny]==h){
	                if(nx==fx && ny==fy)
	                    return board[x][y]+1;
	                board[nx][ny] = board[x][y]+1;;
	                q.push({nx, ny});
	            }
	        }
	    }
	    return board[TargetPos[0]-1][TargetPos[1]-1];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends