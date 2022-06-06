class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target < matrix[0][0]) return false;
       int m = matrix.size();
        int n = matrix[0].size();
        if(target > matrix[m-1][n-1]) return false;
        int i=0;
        
        while(i<m){
            if(matrix[i][n-1] == target) return true;
            else if(matrix[i][n-1] > target) {
                int j=0;
                while(j<n){
                    if(matrix[i][j] == target) return true;
                    j++;
                }
            }
            i++;
        }
        
        return false;
        
    }
};