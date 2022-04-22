// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        int start=0;
        int end = v.size()-1;
        
        int first = 0;
        int last = 0;
        
        int mid = 0;
        
        bool found = false;
        
        while(start<=end){
            mid = start + (end-start)/2;
            
            if(v[mid]==x){
                found = true;
                break;
            }
            else if(v[mid]<x){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            
        }
        
        if(found){
            first = mid;
            last = mid;
            
            while(v[first]==x and first>=0){
                first--;
            }
            
            first++;
            
            
            while(v[last]==x and last<v.size()){
                last++;
            }
            
            last--;
            
           pair<long,long> p = make_pair(first,last);
            
            return p;
            
        }
        else{
            return {-1,-1};
        }
    }
};

// { Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}
  // } Driver Code Ends