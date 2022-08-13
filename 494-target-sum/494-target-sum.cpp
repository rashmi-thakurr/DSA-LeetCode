class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it:nums) sum += it;
        
        if((sum+target)%2!=0) return 0;
        if(sum < abs(target)) return 0;
        
        target = (sum+target)/2;
        
        int dp[n+1][target+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if (nums[i-1]<=j) dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][target];
    }
};