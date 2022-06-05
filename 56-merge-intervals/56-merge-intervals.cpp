class Solution {
public:
    
    bool static comp(vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if(intervals.size()==0) return vector<vector<int>> {};
        
        sort(intervals.begin(),intervals.end(),comp);
        
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(intervals[i][1],ans.back()[1]);
            }
        }
        
        return ans;
    }
};