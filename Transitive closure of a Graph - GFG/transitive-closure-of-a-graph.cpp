// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void dfs(vector<vector<int>> graph, vector<int> &vis, int i,int n){
        vis[i]=1;
        for(int j=0;j<n;j++){
            if(graph[i][j]==1 and vis[j]!=1){
                dfs(graph,vis,j,n);
            }
        }
    }
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        // code here
      vector<vector<int>> ans;
      vector<int> vis(n,0);
      for(int i=0;i<n;i++){
          dfs(graph,vis,i,n);
          ans.push_back(vis);
          for(int j=0;j<n;j++) vis[j]=0;
      }
      return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}  // } Driver Code Ends