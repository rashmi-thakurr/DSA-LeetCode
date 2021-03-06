// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        queue<pair<int,int>> q;
        if(A[0][0]==0) return -1;
        A[0][0] = -1;
        q.push({0,0});
        int steps = -1;
        
        while(!q.empty()){
            int n = q.size();
            steps++;
            for(int p=0;p<n;p++){
              int i = q.front().first;
              int j = q.front().second;
              q.pop();
              
              if(i==X and j==Y) return steps;
              
              if(i-1>=0 and A[i-1][j]==1){
                  A[i-1][j]=-1;
                  q.push({i-1,j});
              }
              
               if(j-1>=0 and A[i][j-1]==1){
                  A[i][j-1]=-1;
                  q.push({i,j-1});
              }
              
               if(i+1<N and A[i+1][j]==1){
                  A[i+1][j]=-1;
                  q.push({i+1,j});
              }
              
               if(j+1<M and A[i][j+1]==1){
                  A[i][j+1]=-1;
                  q.push({i,j+1});
              }
            }
        }
        
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends