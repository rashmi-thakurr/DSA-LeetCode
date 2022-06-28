// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>> adj, int V, int i, vector<int> &vis){
      vis[i]=1;
      for(int j=0;j<V;j++){
          if(!vis[j] and adj[i][j]==1) dfs(adj,V,j,vis);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V,0);
        int numOfProvinces=0;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,V,i,vis);
                numOfProvinces++;
            }
        }
        
        return numOfProvinces;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends