// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void perm(string S, vector<string> &ans, string &a, vector<int> &vis){
        if(a.length() == S.length()){
            ans.push_back(a);
            return;
        }
        
        for(int j=0;j<S.length();j++){
           if(vis[j]==0){
            a.push_back(S[j]);
            vis[j]=1;
            perm(S,ans,a,vis);
            vis[j]=0;
            a.pop_back();
           }
        }
        
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        string a ="";
        vector<int> vis;
        for(auto i:S){
            vis.push_back(0);
        }
        perm(S,ans,a,vis);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}  // } Driver Code Ends