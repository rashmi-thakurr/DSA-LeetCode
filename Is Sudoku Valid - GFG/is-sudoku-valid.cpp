// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
     
      for(int i=0;i<9;i++)
      {
          unordered_map<int,int>map;
          for(int j=0;j<9;j++)
          {
              if(mat[i][j]==0)
              continue;
            map[mat[i][j]]++;
            if(map[mat[i][j]]>1 && mat[i][j]!=0)
            return 0;
               
          }
           
      }
       
      for(int i=0;i<9;i++)
      {
          unordered_map<int,int>map;
          for(int j=0;j<9;j++)
          {
              if(mat[j][i]==0)
              continue;
               
            map[mat[j][i]]++;
            if(map[mat[j][i]]>1 && mat[j][i]!=0)
            return 0;
               
          }
           
      }
       
      for(int k=0;k<9;k+=3)
      {
          for(int l=0;l<9;l+=3)
          {
              int i=k;
                unordered_map<int,int>map;
               
              while(i!=k+3)
              {
                  
                  int j=l;
                  while(j!=l+3)
                  {
                      if(mat[i][j]==0){
                      j++;
                      continue;
                      }
                      map[mat[i][j]]++;
                      
                      if(map[mat[i][j]] >1  && mat[i][j]!=0)
                      return 0;
                       
                        j++;
                  }
                   
                   
                  i++;
              }
               
               
          }
           
      }
       
       
       
       return 1;
       
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends