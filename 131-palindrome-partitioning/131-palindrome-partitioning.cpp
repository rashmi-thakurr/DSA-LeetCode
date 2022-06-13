class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
           
        }
         return true;
    }
    void solve(vector<vector<string>> &ans, vector<string> &v, string s, int i, int N){
        if(i==N){
            ans.push_back(v);
            return;
        }
        
        for(int j=i;j<N;j++){
            if(isPalindrome(s,i,j)){
                v.push_back(s.substr(i,j-i+1));
                solve(ans,v,s,j+1,N);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        int N = s.size();
         solve(ans,v,s,0,N);
        return ans;
        
    }
};