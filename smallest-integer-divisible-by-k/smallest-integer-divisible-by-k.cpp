class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 or k%5==0){
            return -1;
        }
        
        int n=1, remain;
        
        for(int i=1;i<=k;i++){
            remain = n%k;
            if(remain==0) return i;
            n = remain*10 + 1;
        }
        
        return -1;
    }
};