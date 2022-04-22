// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	vector<long long> findMissing(long long A[], long long B[],  
                 int N, int M) 
	{ 
	    // Your code goes here
	    vector<long long> v;
	    unordered_map<long,long> mp;
	    
	    for(long long int i=0;i<N;i++){
	        if(mp.find(A[i])==mp.end()){
	           mp[A[i]]=1; 
	        } 
	    }
	    
	     for(long long int i=0;i<M;i++){
	        mp[B[i]]=0;
	    }
	    
	   // unordered_map<long long int,long long int>::iterator itr;
	    
	   // for(auto itr=mp.begin();itr!=mp.end();itr++){
	   //     if(itr->second==1){
	   //         v.push_back(itr->first);
	   //     }
	   // }
	   
	    for(long long int i=0;i<N;i++){
	        if(mp[A[i]]==1){
	           v.push_back(A[i]);
	        } 
	    }
	    
	    return v;
	} 
	
	
};
	

// { Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        int m;
        cin>>m;
        long long a[n];
        long long b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<long long> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends