// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j]='2';
        //top
        if(i-1>=0 and grid[i-1][j]=='1') bfs(grid,i-1,j);
        //down
        if(i+1<grid.size() and grid[i+1][j]=='1') bfs(grid,i+1,j);
        //left
        if(j-1>=0 and grid[i][j-1]=='1') bfs(grid,i,j-1);
        //right
        if(j+1<grid[0].size() and grid[i][j+1]=='1') bfs(grid,i,j+1);
        //diagonally up left
        if(i-1>=0 and j-1>=0 and grid[i-1][j-1]=='1') bfs(grid,i-1,j-1);
        //diagonally up right
        if(i-1>=0 and j+1<grid[0].size() and grid[i-1][j+1]=='1') bfs(grid,i-1,j+1);
        //diagonally down left
        if(i+1<grid.size() and j-1>=0 and grid[i+1][j-1]=='1') bfs(grid,i+1,j-1);
        //diagonally down right
        if(i+1<grid.size() and j+1<grid[0].size() and grid[i+1][j+1]=='1') bfs(grid,i+1,j+1);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int num=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    num++;
                }
            }
        }
        return num;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends