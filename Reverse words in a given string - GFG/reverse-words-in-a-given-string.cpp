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
        string st;
        int i = S.length()-1;
        int len=0;
        
        while(i>=-1){
            if(S[i]=='.'){
                string x = S.substr(i+1,len);
                st += x;
                st += ".";
                len=0;
            }
            else{
                len++;
            }
           i--;
        }
        
        st += S.substr(0,len-1);
        
        return st;
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