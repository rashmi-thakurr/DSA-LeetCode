// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    vector<int> par;
    vector<int> rank;
    int findPar(int u){
        if(u==par[u]) return u;
        return par[u]=findPar(par[u]);
    }
    void union_(int u ,int v){
        int a = findPar(u);
        int b = findPar(v);
        
        if(rank[a]<rank[b]){
            par[a]=b;
        }
        else if(rank[b]<rank[a]){
            par[b]=a;
        }
        else{
            par[a]=b;
            rank[b]++;
        }
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    par.resize(V);
	    
	    rank.resize(V);
	    
	    for(int i=0;i<V;i++){
	        par[i]=i;
	        rank[i]=1;
	    }
	    
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            if(i<=it){
	                int x = findPar(i);
	                int y = findPar(it);
	                if(x==y) return 1;
	                union_(x,y);
	            }
	        }
	    }
	    
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends