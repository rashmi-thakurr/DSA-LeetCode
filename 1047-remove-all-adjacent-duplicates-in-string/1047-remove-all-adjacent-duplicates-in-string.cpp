class Solution {
public:
    string removeDuplicates(string s) {
        if(s==""){
            return s;
        }
       stack<char> st;
        st.push(s[0]);
        int i=1;
        while(i<s.length()){
            if(!st.empty() && s[i]==st.top()){
                st.pop();   
                // cout<<"inside if block"<<endl;
            }
            else{
                // cout<<"inside else block"<<endl;
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            // cout<<st.top();
            char a = st.top();
            st.pop();
            ans = a+ ans;
        }
        
        return ans;
    }
};