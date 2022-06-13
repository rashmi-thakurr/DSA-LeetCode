class Solution {
public:
    void solve(vector<int> &candidates, vector<int> &arr, vector<vector<int>> &ans, int i, int N, int target, int sum){
       if(i==N){
            if(sum==target){
                ans.push_back(arr);
            }
            return;
       }
        
        if(candidates[i]<=target-sum){
            arr.push_back(candidates[i]);
            sum += candidates[i];
            solve(candidates, arr, ans, i, N,target, sum);
            sum -= candidates[i];
            arr.pop_back();
        }
           
            solve(candidates, arr, ans, i+1, N, target, sum);
       
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(candidates, arr, ans, 0, candidates.size(), target, 0);
        return ans;
    }
};