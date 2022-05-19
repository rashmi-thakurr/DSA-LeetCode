// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
   void cs(vector<int> &v, vector<vector<int>> &ans, vector<int> &A, int target, int ind){
       if(target == 0){
           ans.push_back(v);
           return;
       }
       if(ind == A.size()){
           return;
       }
       if(A[ind] <= target){
           v.push_back(A[ind]);
           cs(v,ans,A,target-A[ind],ind);
           v.pop_back();
       }
       cs(v,ans,A,target,ind+1);
   }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        vector<vector<int>> ans;
        vector<int> v;
        cs(v,ans,A,B,0);
        
        // unordered_map<vector<int>,int> mp;
        // vector<int> 
        // for(it : a){
        //     mp[it]++;
        //     if(mp[it]==1){
        //         ans.push_back(it);
        //     }
        // }
        
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends