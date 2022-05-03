// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int r = grid.size();
        int c = grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=-1;
                }
            }
        }
        
        while(!q.empty()){
            int n=q.size();
            for(int p=0;p<n;p++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i-1>=0 and grid[i-1][j]==2){
                    return true;
                }
                if(i+1<r and grid[i+1][j]==2){
                    return true;
                }
                if(j-1>=0 and grid[i][j-1]==2){
                    return true;
                }
                if(j+1>=0 and grid[i][j+1]==2){
                    return true;
                }
                if(i-1>=0 and grid[i-1][j]==3){
                    grid[i-1][j]=-1;
                    q.push({i-1,j});
                }
                if(i+1<r and grid[i+1][j]==3){
                     grid[i+1][j]=-1;
                    q.push({i+1,j});
                }
                if(j-1>=0 and grid[i][j-1]==3){
                     grid[i][j-1]=-1;
                    q.push({i,j-1});
                }
                if(j+1<c and grid[i][j+1]==3){
                     grid[i][j+1]=-1;
                    q.push({i,j+1});
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends