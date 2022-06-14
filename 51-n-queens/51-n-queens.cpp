class Solution {
public:
    // bool isRowSafe(vector<string> grid, int i, int cols){
    //     for(int j=0;j<cols;j++){
    //         if(grid[i][j]=='Q') return false;
    //     }
    //     return true;
    // }
    bool isColSafe(vector<string> grid, int rows, int j){
        for(int i=0;i<rows;i++){
            if(grid[i][j]=='Q') return false;
        }
        return true;
    }
    bool isDiagonallySafe(vector<string> grid, int i, int j, int cols){
        int k = i-1;
        int l = j-1;
        
        while(k>=0 and l>=0){
            if(grid[k--][l--]=='Q') return false;
        }
        
        k=i-1;
        l=j+1;
        
        while(k>=0 and l<cols){
            if(grid[k--][l++]=='Q') return false;
        }
        
        return true;
        
    }
    bool isSafe(vector<string> grid, int rows, int cols, int i, int j){
       return isColSafe(grid, rows, j) and isDiagonallySafe(grid,i,j,cols); 
    }
    
//     bool check(vector<string> grid, int rows, int cols){
//         int i=0;
//         while(i<rows){
//             int cnt = 0;
//             for(int j=0;j<cols;j++){
//                if(grid[i][j]=='Q') cnt++; 
//             }
            
//             if(cnt != 1) return false;
//             i++;
//         }
        
//         return true;
//     }
    void solve( vector<vector<string>>&ans, vector<string> &grid, int rows, int cols, int i){
        if(i==rows){
            ans.push_back(grid);
            return;
        }
        
        for(int j=0;j<cols;j++){
            if(isSafe(grid,rows,cols,i,j)){
                grid[i][j] = 'Q';
                solve(ans, grid, rows, cols, i+1);
                grid[i][j] = '.';
            }
            // solve(ans, grid, rows, cols, i+1);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // vector<string> grid;
        int rows = n;
        int cols = n;
        vector<string> board(n,string(n,'.'));
        solve(ans, board, rows, cols, 0);
        
        return ans;
    }
};