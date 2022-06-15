class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if(end==0) return nums[0];
        int mid = (start+end)/2;
        while(start<end){
            mid = ( start + end )/2;
            if(mid>0 and nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]) return nums[mid];
            else if(mid>0 and nums[mid]==nums[mid-1] and mid%2==0) end = mid;
            else if(mid>0 and nums[mid]==nums[mid-1] and mid%2!=0) start=mid+1;
            else if(mid<nums.size()-1 and nums[mid]==nums[mid+1] and mid%2==0) start=mid+1;
            else if(mid<nums.size()-1 and nums[mid]==nums[mid+1] and mid%2!=0) end = mid;
            else break;
        }
        return nums[start];
    }
};