// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
   
    
    void solve(vector<string> &ans, string ds, int open, int close, int n){
       
        if(open == n and close == n){
            ans.push_back(ds);
            return;
        }
        
        if(open < n){
            solve(ans, ds + "(", open+1, close, n);
        }
        
         if(close < open){
            solve(ans, ds + ")", open, close+1, n);
        }
        
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string ds;
        solve(ans,ds,0,0,n);
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends