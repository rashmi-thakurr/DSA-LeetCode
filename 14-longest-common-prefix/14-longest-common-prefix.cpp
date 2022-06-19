class Solution {
public:
    string lcp(string a, string b){
        if(a=="" or b=="") return "";
        int i=0;
        int j=0;
        string ans = "";
        while(a[i]==b[j] and i<a.length() and j<b.length()) {
            ans += a[i];
            i++;
            j++;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";
        if(strs.size()==1)return strs[0];
        ans = lcp(strs[0],strs[1]);
        int i=2;
        while(i<strs.size()){
            ans = lcp(ans,strs[i]);
            i++;
        }
        return ans;
    }
};