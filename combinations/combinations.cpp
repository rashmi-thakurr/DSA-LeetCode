class Solution {
public:
   vector<vector<int>> ans;
    
    void helper(vector<int> &v, int pos, int n, int k)
    {
        if(v.size()==k)   
        {
            ans.push_back(v);
            return;
        }
        
        for(int i=pos;i<n+1;i++)
        {
            v.push_back(i);  
            helper(v,i+1,n,k); 
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        helper(v,1,n,k);
        return ans; 
    }
};