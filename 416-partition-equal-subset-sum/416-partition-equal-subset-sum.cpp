class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums) sum+=i;
        
        if( sum%2 != 0 ) return false;
        
        int target = sum/2;
        
        int dp[nums.size()+1][target+1];
        
        for(int i=0;i<nums.size()+1;i++){
            for(int j=0;j<target+1;j++){
                if(i==0 or j==0) dp[i][j] = 0;
            }
        }
        
        dp[0][0] = 1;
        
        for(int i=1;i<nums.size()+1;i++){
            for(int j=1;j<target+1;j++){
                if(nums[i-1]<=j) dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[nums.size()][target];
    }
};