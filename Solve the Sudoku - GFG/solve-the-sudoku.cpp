// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isRow(int j, int grid[N][N], int k){
        for(int i=0;i<9;i++){
            if(grid[i][j] == k) return false;
        }
        
        return true;
    }
    bool isCol(int i, int grid[N][N], int k){
        for(int j=0;j<9;j++){
            if(grid[i][j] == k) return false;
        }
        
        return true;
    }
    bool isSubbox(int grid[N][N], int k, int i, int j){
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
        
        for(int m=row_start;m<row_end;m++){
            for(int n=col_start;n<col_end;n++){
                if(grid[m][n]==k) return false;
            }
        }
        
        return true;
    }
    
    bool isSafe(int grid[N][N], int i, int j, int k){
        return (isRow(j,grid,k) and isCol(i,grid,k) and isSubbox(grid,k,i,j));
    }
    
    bool sudoku(int i, int j, int grid[N][N]){
        if(i==N) return true;
        
        if(grid[i][j]!=0){
            if(j==8){
                return sudoku(i+1,0,grid);
            }
            else{
                return sudoku(i,j+1,grid);
            }
        }
        
        for(int k=1;k<=9;k++){
            if(isSafe(grid,i,j,k)){
                grid[i][j] = k;
                    if(j==8){
                        if(sudoku(i+1,0,grid)) return true;
                    }
                    else{
                        if(sudoku(i,j+1,grid)) return true;
                    }
                grid[i][j] = 0;
            }
        }
        
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here'
         return sudoku(0,0,grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
         int i,j;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends