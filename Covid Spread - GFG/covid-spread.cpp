// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int r = hospital.size();
        int c = hospital[0].size();
        
        queue<pair<int,int>> q;
        int covid=0;
        int nonCovid=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==2){
                   q.push({i,j});
                   hospital[i][j]=-1;
                   covid++;
                }
                else if(hospital[i][j]==1){
                    nonCovid++;
                }
            }
        }
        
        if(covid==0 and nonCovid>0) return -1;
        if(nonCovid==0) return 0;
        
        int t=-1;
        int covidLater=0;
        while(!q.empty()){
            int n = q.size();
            t++;
            for(int p=0;p<n;p++){
                int i = q.front().first;
                int j = q.front().second;
                
                q.pop();
                
                if(i-1>=0 and hospital[i-1][j]==1){
                    hospital[i-1][j] = -1;
                    covidLater++;
                    q.push({(i-1),j});
                }
                
                if(i+1<r and hospital[i+1][j]==1){
                    hospital[i+1][j] = -1;
                    covidLater++;
                    q.push({(i+1),j});
                }
                
                if(j-1>=0 and hospital[i][j-1]==1){
                    hospital[i][j-1] = -1;
                    covidLater++;
                    q.push({i,j-1});
                }
                
                if(j+1<c and hospital[i][j+1]==1){
                    hospital[i][j+1] = -1;
                    covidLater++;
                    q.push({i,j+1});
                }
            }
        }
        if(nonCovid != covidLater) return -1;
        return t;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends