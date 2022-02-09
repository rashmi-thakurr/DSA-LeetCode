// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

 // } Driver Code Ends

class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(n%10);
            n = n/10;
        }
        // v.push_back(n);
        if(n!=0){
            v.push_back(n);
        }
        int ans = 0;
        for(int i=v.size()-1;i>=0;i--){
            // cout<<v[i]<<endl;
            if(v[i]==0){
                v[i]=5;
            }
            
            ans = ans*10 + v[i];
            // cout<<ans<<endl;
        }
        
        return ans;
    }
    
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}  // } Driver Code Ends