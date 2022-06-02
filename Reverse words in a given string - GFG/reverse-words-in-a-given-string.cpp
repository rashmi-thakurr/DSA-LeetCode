// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.length();
       vector<string> v;
       int i=0;
       int j=0;
       while(i<n and j<n){
          while(S[j]!='.' and j<n){
              j++;
          } 
          v.push_back(S.substr(i,j-i));
          i=j+1;
          j=j+1;
          
       }
       string ans;
       for(int i=v.size()-1;i>=0;i--){
           ans += v[i];
           if(i!=0) ans += '.';
       }
       return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends