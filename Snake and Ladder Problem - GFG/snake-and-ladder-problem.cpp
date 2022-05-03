// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
          queue<pair<int,int>> q;
       vector<int> vis(31,0);
       vector<int>moves(31,-1);
       for(int i=0;i<2*N;i=i+2)
       {
           moves[arr[i]]=arr[i+1];
       }
       q.push({1,0});
       vis[1]=1;
       while(!q.empty())
       {
           pair<int,int> p=q.front();
           q.pop();
           int cell=p.first;
           int turn=p.second;
           if(cell==30)
           return p.second;
           for(int i=cell+1;i<=cell+6&&i<=30;i++)
           {
               pair<int,int> pp;
               if(!vis[i])
               {
                   vis[i]=1;
                   if(moves[i]!=-1)
                   pp.first=moves[i];
                   else
                   pp.first=i;
                   
                   pp.second=turn+1;
                   q.push(pp);
               }
           }
       }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends