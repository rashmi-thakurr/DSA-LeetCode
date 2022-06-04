class Solution {
public:
    int maxProfit(vector<int>& nums) {
       int n=nums.size();
        vector<int> pft(n,-1);
        
        for(int i=n-2;i>=0;i--){
            pft[i] = max(nums[i+1],pft[i+1]);
        }
        
        int profit=0;
        
        for(int i=0;i<n;i++){
            if(pft[i]-nums[i] > 0){
                profit = max(pft[i]-nums[i],profit);
            }
        }
        
        return profit;
    }
};