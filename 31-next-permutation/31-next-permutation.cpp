class Solution {
public:
    void nextPermutation(vector<int>& nums) {
//         string s;
//         for(int i=0;i<nums.size();i++){
//             s += to_string(nums[i]);
//         }
//         string s1 = s;
//         next_permutation(s.begin(),s.end());
//         if(s<s1){
//             sort(nums.begin(),nums.end());
//             return;
//         }
        
//         for(int i=0;i<nums.size();i++){
//            nums[i] = s[i] - '0';
//         }
        
         next_permutation(nums.begin(),nums.end());
        
        return;        
    }
};