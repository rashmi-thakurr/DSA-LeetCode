class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int ans = INT_MIN;
        int count = 0;
        
        while(i<nums.size()){
            if(nums[i]==1) count++;
            else count = 0;
            
            ans = max(ans,count);
            
            i++;            
        }
        
        return ans;
    }
};