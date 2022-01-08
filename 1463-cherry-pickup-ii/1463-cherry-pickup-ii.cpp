class Solution {
public:
    int dy[3] = {0, -1, 1};
    int dp[71][71][71];
    
     int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return cherry(grid,0,0,m-1);
       
    }
    int cherry(vector<vector<int>>& grid, int i, int c1, int c2) {
       int n = grid.size();
        int m = grid[0].size();
        if (i == n) return 0;
        if (c1 < 0 || c2 < 0 || c1 >= m || c2 >= m) return INT_MIN;
        if (dp[i][c1][c2] != -1) return dp[i][c1][c2];
        
        int c = 0;
        
        for (int k=0; k<3; k++) {
            for (int r=0; r<3; r++) {
                c = max(c, cherry(grid, i + 1, c1 + dy[k], c2 + dy[r]));
            }
        }
        
        c += (c1 == c2) ? grid[i][c1] : grid[i][c1] + grid[i][c2];
        return dp[i][c1][c2] = c;
    }
   
    
   
};