class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
        
//         for(int i=0;i<s.length();i++){
//             if(s[i]!=t[i]){
//                 return false;
//             }
//         }
//         return true;
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        for(int i=0;i<t.length();i++) mp[t[i]]--;
        
        for(auto i:mp){
            if(i.second != 0) return false;
        }
        
        return true;
        
    }
};