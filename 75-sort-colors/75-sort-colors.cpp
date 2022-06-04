class Solution {
public:
    void sortColors(vector<int>& nums) {
       int c0=0;
        int c1=0;
        int c2 = 0;
        int n =  nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==0) c0++;
            else if(nums[i]==1) c1++;
            else c2++;
        }
        int i=0;
        while(c0--){
            nums[i]=0;
            i++;
        }
        while(c1--){
            nums[i]=1;
            i++;
        }
        while(c2--){
            nums[i]=2;
            i++;
        }
      
    }
};