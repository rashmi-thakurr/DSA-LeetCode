// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            int ans = 0;
            string temp="";
            int cnt=0;
            int check=0;
            
            for(int i=0;i<s.length();i++){
                if(s[i]=='.') cnt++;
            }
            
            if(cnt!=3){
                return 0;
            }
            
            for(int i=0;i<s.length();i++){
                if(isalpha(s[i])) return 0;
                
                if(s[i]=='0' and s[i+1]!='.' and i+1<s.length()){
                    return false;
                }
                
                if(s[i]=='.'){
                    if(s[i+1]=='.' and i+1<s.length()){
                        return 0;
                    }
                    temp="";
                    check=0;
                    continue;
                }
                
                temp+=s[i];
                check++;
                ans = stoi(temp);
                
                if(ans>255 or (ans==0 and check>1)){
                    return 0;
                }
            }
            
            return 1;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends