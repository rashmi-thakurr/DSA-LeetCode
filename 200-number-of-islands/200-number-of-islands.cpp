class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        grid[i][j]='2';
        //Up
        if(i-1>=0 and grid[i-1][j]=='1') dfs(grid,i-1,j,m,n);
        //Down
        if(i+1<n and grid[i+1][j]=='1') dfs(grid,i+1,j,m,n);
        //Left
        if(j-1>=0 and grid[i][j-1]=='1') dfs(grid,i,j-1,m,n);
        //Righ
        if(j+1<m and grid[i][j+1]=='1') dfs(grid,i,j+1,m,n);
       
    }
    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        int n = grid.size();
        int m = grid[0].size();
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]=='1'){
                   dfs(grid,i,j,m,n);
                   num++;
               }
           }
       }
        
        return num;
        
    }
};