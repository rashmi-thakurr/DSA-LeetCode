// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> graycode(int n)
    {
        //code here
        vector<string> v;
        
        if(n==0) return v;
        if(n==1){
            v.push_back("0");
            v.push_back("1");
            return v;
        }
        
        v = graycode(n-1);
        
        vector<string> ans;
        int k=v.size();
        
        for(int i=0;i<k;i++){
            ans.push_back("0"+v[i]);
        }
        
        for(int i=k-1;i>=0;i--){
            ans.push_back("1"+v[i]);
        }
        
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
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}



  // } Driver Code Ends