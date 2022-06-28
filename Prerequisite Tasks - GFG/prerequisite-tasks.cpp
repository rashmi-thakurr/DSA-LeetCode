// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis){
        vis[src]=1;
        dfsvis[src]=1;
        for(auto x:adj[src]){
            if(!vis[x]){
                if(dfs(x,adj,vis,dfsvis)) return true;
            }
            else if(dfsvis[x]) return true;
        }
        dfsvis[src]=false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    vector<int> vis(N,0);
	    vector<int> dfsvis(N,0);
	    bool f = false;
	    
	    for(auto i:prerequisites){
	        adj[i.second].push_back(i.first);
	    }
	    
	    for(int i=0;i<N;i++){
	        if(!vis[i]){
	            if(dfs(i,adj,vis,dfsvis)) f = true;
	        }
	    }
	    
	    if(f) return false;
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends