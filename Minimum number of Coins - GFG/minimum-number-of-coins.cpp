// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<int> minPartition(int N)
    {
        // code here
        int  n = 10;
        int  currency[n] = {1,2,5,10,20,50,100,200,500,2000};
    
        vector<int> ans;
        int i=n-1;
        
        while(N){
            if(N>=currency[i]){
                N=N-currency[i];
                ans.push_back(currency[i]);
            }
            else{
                i--;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends