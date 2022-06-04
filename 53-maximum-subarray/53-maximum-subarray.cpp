class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        int curr = 0;
        int n = nums.size();
        
        int i=0;
        while(i<n){
            curr += nums[i];
            mx = max(mx,curr);
            curr = curr<0 ? 0 : curr;
            i++;
        }
        
        return mx;
    }
};