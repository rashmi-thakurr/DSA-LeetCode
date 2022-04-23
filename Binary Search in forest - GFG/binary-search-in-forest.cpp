// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        // code here
        int start = 0;
        int end = 0;
        int mid = 0;
        int wood = 0;
        int mx = tree[0];
        
        for(int i=1;i<n;i++){
            if(tree[i]>=mx){
                mx = tree[i];
            }
        }
        end = mx;
        while(start<=end){
            mid = start + (end - start)/2;
            
            for(int j=0;j<n;j++){
                if(tree[j]>=mid){
                    wood += (tree[j] - mid);
                }
            }
            
            if(wood==k){
                return mid;
            }
            else if(wood<k){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            
            wood=0;
        }
        
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends