class Solution {
public:
    int solve(string s,vector<string>& wordDict,int i,int j,int len,vector<vector<int>> &dp){
        if(j==len){
            if(i==len) return 1;
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(find(wordDict.begin(),wordDict.end(),s.substr(i,j-i+1))==wordDict.end()){
            return dp[i][j] = solve(s,wordDict,i,j+1,len,dp);
        }
        else{
            int x = solve(s,wordDict,j+1,j+1,len,dp);
            int y = solve(s,wordDict,i,j+1,len,dp);
            return dp[i][j] = x or y;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,wordDict,0,0,n,dp);
    }
};