class Solution {
public:
    void permutation(vector<vector<int>> &ans,vector<int>& nums, int pos,int len){
        if(pos==len-1)
        {
            ans.push_back(nums);
        }
         
        for(int i=pos;i<len;i++){
            swap(nums[pos],nums[i]);
            permutation(ans,nums,pos+1,len);
            swap(nums[pos],nums[i]);
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
        int len = nums.size();
        permutation(ans,nums,0,len);
        
        return ans;
    }
};