class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax = 1;
        int currmin = 1;
        int ans =INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                currmax = max(nums[i],currmax*nums[i]);
                currmin = min(nums[i],nums[i]*currmin);
            }
            else{
                int tmp = currmax;
                currmax = max(currmin*nums[i],nums[i]);
                currmin = min(tmp*nums[i],nums[i]);
            }
            ans = max(currmax,ans);
        }
        return ans;
    }
};