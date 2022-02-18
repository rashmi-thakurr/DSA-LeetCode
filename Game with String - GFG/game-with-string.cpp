// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        
        while(k--){
            int maxCount = INT_MIN;
            char ch;
            for(auto x:m){
                if(x.second > maxCount){
                    maxCount=x.second;
                    ch = x.first;
                }
            }
            m[ch]--;
        }
        
        int ans=0;
        for(auto x:m){
            ans += pow(x.second,2);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends