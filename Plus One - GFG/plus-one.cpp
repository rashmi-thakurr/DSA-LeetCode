// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
        arr[N-1] += 1;
        int carry = 0;
         carry = arr[N-1] > 9 ? 1 : 0;
        
        arr[N-1] = arr[N-1] > 9 ? arr[N-1]%10 : arr[N-1];
       
        for(int i=N-2;i>=0;i--){
            if(arr[i]+carry > 9){
                arr[i] = (arr[i] + carry)%10;
                carry = 1;
            }
            else{
                arr[i] = arr[i]+carry;
                carry=0;
                break;
            }
        }
        
        if(carry){
            arr.insert(arr.begin(),1);
        }
        
        return arr;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends