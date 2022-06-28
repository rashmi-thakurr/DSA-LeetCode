// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    bool dfs(int src, vector<int> adj[], vector<int> vis, int cnt, int N){
        vis[src]=1;
        if(cnt==N) return true;
        for(auto x:adj[src]){
            if(!vis[x]){
                if(dfs(x,adj,vis,cnt+1,N)) return true;
            }
        }
        vis[src]=false;
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int> adj[N+1];
        vector<int> vis(N+1,0);
        
        for(auto x:Edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        for(int i=1;i<N+1;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,1,N)) return true;
            }
        }
        
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends