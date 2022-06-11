class Solution {
public:
    int trap(vector<int>& height) {
        
        int res=0;
        int n = height.size();
        
        int leftmax[n];
        int rightmax[n];
        
        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];
        
        for(int i=1;i<n;i++){
            leftmax[i] = max(height[i],leftmax[i-1]);
        }
        
        for(int i=n-2;i>=0;i--){
            rightmax[i] = max(height[i],rightmax[i+1]);
        }
        
        for(int i=1;i<n-1;i++){
            res += min(leftmax[i],rightmax[i])-height[i];
            // cout<<res<<endl;
        }
        
        return res;
    }
};