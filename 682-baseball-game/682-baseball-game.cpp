class Solution {
public:
    int calPoints(vector<string>& v) {
        stack<int> st;
        
        for(int i=0;i<v.size();i++){
            if(v[i]=="+"){
                int x = st.top();
                st.pop();
                int y= st.top();
                st.push(x);
                st.push(x+y);
            }
            else if(v[i]=="C"){
                st.pop();
            }
            else if(v[i]=="D"){
                st.push(2*st.top());
            }
            else{
                st.push(stoi(v[i]));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};