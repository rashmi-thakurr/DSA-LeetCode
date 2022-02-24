// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        if(k==1) return "";
        stack<char> st;
        for(int i=0;i<s.length();i++){
                st.push(s[i]);
               int count=0;
                    while(!st.empty() and st.top()==s[i]){
                        st.pop();
                        count++;
                    }
                    if(count==k){
                        continue;
                    }
                    else if(count>k){
                        int val = count-k;
                        while(val--){
                            st.push(s[i]);
                        }
                    }
                    else{
                        while(count--){
                            st.push(s[i]);
                        }
                    }

                }
            
            
               
            
        
        string ans = "";
        while(!st.empty()){
            ans += st.top() ;
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends