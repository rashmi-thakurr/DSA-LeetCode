class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='#' && !s1.empty()){
                s1.pop();
            }
            else if(s[i]!='#'){
                s1.push(s[i]);
            }
        }
        
        for(int i=0;i<t.length();i++){
            if(t[i]=='#' && !s2.empty()){
                s2.pop();
            }
            else if(t[i]!='#'){
                s2.push(t[i]);
            }
        }
        
        while(!s1.empty() and !s2.empty()){
            if(s1.top()!=s2.top()){
                return false;
            }
            s1.pop();
            s2.pop();
        }
        
        if(!s1.empty() or !s2.empty()){
            return false;
        }
        
        return true;
    }
};