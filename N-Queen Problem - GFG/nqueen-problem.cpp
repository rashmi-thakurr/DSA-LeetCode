// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isSafe(vector<vector<int>> &chess,int x, int y, int n){
        for(int i=0;i<y;i++){
            if(chess[x][i]==1){
                return false;
            }
        }
        
        for(int i=x-1,j=y-1;i>=0 and j>=0;i--,j--){
             if(chess[i][j]==1){
                return false;
            }
        }
        
         for(int i=x+1,j=y-1;i<n and j>=0;i++,j--){
             if(chess[i][j]==1){
                return false;
            }
        }
        
        return true;
    }

   void solve(vector<vector<int>> &chess, vector<int> &v, int j, int N, vector<vector<int>> &ans){
       if(v.size()==N){
           ans.push_back(v);
           return;
       }
      
       
       for(int i=0;i<N;i++){
           if(isSafe(chess,i,j,N)){
               v.push_back(i+1);
               chess[i][j] = 1;
               solve(chess,v,j+1,N,ans);
               chess[i][j] = 0;
               v.pop_back();
           }
       }
   }
    vector<vector<int>> nQueen(int n) {
        // code here
        
        vector<vector<int>> ans;
         vector<vector<int>>board(n , vector<int>(n , 0));
       vector<int> v;
      //  vector<int> a;
       // int col=0;
        //int row=0;
        solve(board,v,0,n,ans);
        sort(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends