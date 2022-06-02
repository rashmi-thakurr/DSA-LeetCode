// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans = 0;
        
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])) return -1;
            if(s[i]-'0' >=0 and s[i]-'0'<=9) ans = ans*10 + (int) (s[i]-'0');
            else if(i!=0) return -1;
        }
        
        if(s[0]=='-') ans = ans*(-1);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends