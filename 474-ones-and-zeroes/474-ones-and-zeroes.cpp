class Solution {
public:
     int dp[601][101][101]; 
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();

        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<len+1;i++){
            for(int j=0;j<m+1;j++){
                for(int k=0;k<n+1;k++){
                   if((j==0 and k==0) or i==0) dp[i][j][k] = 0;
                    else{
                         int count_0 = count(strs[i-1].begin(),strs[i-1].end(),'0');
                        int count_1 = strs[i-1].length()-count_0;
                        if(count_0<=j and count_1<=k){
                    dp[i][j][k] = max(1+dp[i-1][j-count_0][k-count_1],dp[i-1][j][k]);
                        }
                        else dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        
        return dp[len][m][n];
    }
};