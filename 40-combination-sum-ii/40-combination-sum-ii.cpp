class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &arr, vector<int>& candidates, int i,int N, int target){
        
            if(target==0){
                ans.push_back(arr);
                return;
            } 
       
       for(int j=i;j<N;j++){
           if(j>i and candidates[j]==candidates[j-1]) continue;
            if(candidates[j]>target) break;
           
            arr.push_back(candidates[j]);
            solve(ans, arr, candidates, j+1, N, target-candidates[j]);
            arr.pop_back();
            
                
       }
        
       
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(),candidates.end());
        solve(ans, arr, candidates, 0,candidates.size(), target);
        return ans;
    }
};