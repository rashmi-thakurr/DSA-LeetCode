// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void solve(vector<int> &arr, int N, int i, int sum, vector<int> &ans){
        if(i==N){
            ans.push_back(sum);
            return;
        }
        
        sum += arr[i];
        solve(arr,N,i+1,sum,ans);
        sum -= arr[i];
        solve(arr,N,i+1,sum,ans);
    }
  
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
       vector<int> ans;
       solve(arr,N,0,0,ans);
       reverse(ans.begin(),ans.end());
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends