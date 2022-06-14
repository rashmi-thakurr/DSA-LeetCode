class Solution {
public:
    bool isRowSafe(vector<vector<char>> &board, int i, char k){
        for(int j=0;j<9;j++){
            if(board[i][j]==k) return false;
        }
       
        return true;
    }
    bool isColSafe(vector<vector<char>> &board, int j, char k){
        for(int i=0;i<9;i++){
            if(board[i][j]==k) return false;
        }
         
        return true;
    }
    bool isBoxSafe(vector<vector<char>> &board, int i, int j, char k){
        int row_start, row_end, col_start, col_end;
        for(int m=0;m<9;m+=3){
            if(i>=m and i<m+3){
                row_start = m;
                row_end = m+3;
            }
            
             if(j>=m and j<m+3){
                col_start = m;
                col_end = m+3;
            }
        }
        
        for(int x = row_start;x<row_end;x++){
            for(int y = col_start;y<col_end;y++){
                if(board[x][y] == k) return false;
            }
        }
        
        return true;
        
    }
    bool isSafe(vector<vector<char>> &board, int i, int j, char k){
        return isRowSafe(board, i, k) and isColSafe(board, j, k) and isBoxSafe(board, i, j, k);
    }
    
   
    bool solve(vector<vector<char>> &board, int i, int j){
        if(i==9){
            return true;
        }
        if(j==9) return solve(board,i+1,0);
        if(board[i][j] != '.'){
           return solve(board,i,j+1);
        }
        
        for(char k='1';k<='9';k++){
            if(isSafe(board, i, j, k)){
                board[i][j] = k;
                if(solve(board,i,j+1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};