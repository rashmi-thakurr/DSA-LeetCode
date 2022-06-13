class Solution {
public:
    void permutation(vector<vector<int>> &ans,vector<int>& nums, int pos,int len){
       if(pos==len){
           ans.push_back(nums);
           return;
       }
        
        for(int i=pos;i<len;i++){
            swap(nums[i],nums[pos]);
            permutation(ans,nums,pos+1,len);
            swap(nums[i],nums[pos]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(ans,nums,0,nums.size());
        return ans;
    }
};