// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N, long long int A[])
    {
        // code here
        long long int ans=0;
        long long int m = 1000000007;
        
        for(int i=0;i<32;i++){
            long long int count=0;
            for(int j=0;j<N;j++){
                if((A[j] & (1<<i))){
                    count++;
                }
            }
            
            ans += ((count%m)*((N-count)%m)*2)%m;
        }
        
        return ans%m;
        
        //  const int p = 1000000007;
        // long long int ans = 0;
        // for(int j=0; j<32; j++)
        // {
        //     long long int n = 0, m=0;
        //     for(int i=0; i<N; i++)
        //     {
        //         if(A[i]&(1<<j))
        //             n++;
        //         else
        //             m++;
        //     }
        //     ans = (ans + 2*n*m)%p;
        // }
        // return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends