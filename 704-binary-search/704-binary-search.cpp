class Solution {
public:
   int bsearch(vector<int> &nums, int target, int l, int r){
       if(r>=l){
            int m = (l+r)/2;
            if(target == nums[m]) return m;
            return target > nums[m] ?  bsearch(nums,target,m+1,r) : bsearch(nums,target,l,m-1);
       }
       
       return -1;
      
   }
    int search(vector<int>& nums, int target) {
        //Recursive
        int r = nums.size()-1;
        int ans = bsearch(nums,target,0,r);
        return ans;
        
    }
};