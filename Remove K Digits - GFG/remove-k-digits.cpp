// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        
        stack<char> s;
        for(int i=0;i<S.length();i++){
            while(!s.empty() && K>0 && s.top()>S[i]){
                s.pop();
                K--;
            }
            
            if(!s.empty() || S[i]!='0'){
                s.push(S[i]);
            }
        }
        
        while(!s.empty() && K--){
            s.pop();
        }
        
        if(s.empty()){
            return "0";
        }
        
        string ans="";
        while(!s.empty()){
            ans = s.top() + ans;
            s.pop();
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}
  // } Driver Code Ends