// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    // void perm(string S, vector<string> &ans, string &a, vector<int> &vis){
    //     if(a.length() == S.length()){
    //         ans.push_back(a);
    //         return;
    //     }
        
    //     for(int j=0;j<S.length();j++){
    //       if(vis[j]==0){
    //         a.push_back(S[j]);
    //         vis[j]=1;
    //         perm(S,ans,a,vis);
    //         vis[j]=0;
    //         a.pop_back();
    //       }
    //     }
        
    // }
    void perm2(string S, vector<string> &ans, int ind){
        if(ind == S.length()-1){
            ans.push_back(S);
            return;
        }
        
        for(int j=ind;j<S.length();j++){
            swap(S[ind],S[j]);
            perm2(S,ans,ind+1);
            swap(S[ind],S[j]);
        }
        
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        // string a ="";
        // vector<int> vis;
        // for(auto i:S){
        //     vis.push_back(0);
        // }
        perm2(S,ans,0);
        
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