// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int t[201][201];
    Solution(){
        memset(t,-1,sizeof(t));
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        
        if(k==0 or k==1) return k;
        if(n==1) return k;
        
        if(t[n][k]!=-1) return t[n][k];
        
        int ans = INT_MAX;
        
        for(int i=1;i<k;i++){
            int low,high;
            if(t[n-1][i-1]!=-1){
                low = t[n-1][i-1];
            }
            else{
                low = eggDrop(n-1,i-1);
                t[n-1][i-1] = low;
            }
            
            if(t[n][k-i]!=-1){
                high = t[n][k-i];
            }
            else{
                high = eggDrop(n,k-i);
                t[n][k-i] = high;
            }
            
            int temp = 1+max(low,high);
            ans = min(temp,ans);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends