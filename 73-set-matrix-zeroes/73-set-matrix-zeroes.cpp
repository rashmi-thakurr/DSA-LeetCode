class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       vector<pair<int,int>> v;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rvis(n,0);
        vector<int> cvis(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                }
            }
        }
        
        for(auto i:v){
            if(rvis[i.first]==0){
                rvis[i.first]=1;
                for(int j=0;j<m;j++){
                    matrix[i.first][j]=0;
                }
            }
           if(cvis[i.second]==0){
                cvis[i.second]=1;
               for(int j=0;j<n;j++){
                matrix[j][i.second]=0;
            } 
           }
            
        }
    }
};