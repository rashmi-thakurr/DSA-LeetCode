class Solution {
public:
    bool isValid(string s) {
       stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else if(st.empty()){
                return false;
            }
            else if( (s[i]==']' and st.top()!='[')  or (s[i]=='}' and st.top()!='{') or (s[i]==')' and st.top()!='(') ){
                return false;
            }
            else{
                st.pop();
            }
        }
        
        return st.empty();
    }
};