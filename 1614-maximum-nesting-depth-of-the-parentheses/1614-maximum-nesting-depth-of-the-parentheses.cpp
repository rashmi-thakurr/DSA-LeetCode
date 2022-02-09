class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count=0;
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
                count++;
            }
            else if(s[i]==')'){
                st.pop();
                count--;
            }
            
               ans = max(ans,count); 
            
        }
        
        return ans;
    }
};