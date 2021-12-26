class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int r = grid.size();
        
        int c = grid[0].size();
        
        int count=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                   count += (i==0 || grid[i-1][j]==0 ? 1 : 0);
                   count += (i==r-1 || grid[i+1][j]==0 ? 1 : 0);  
                   count += (j==0 || grid[i][j-1]==0 ? 1 : 0); 
                   count += (j==c-1 || grid[i][j+1]==0 ? 1 : 0); 
                }
            }
        }
        
        return count;
    }
};