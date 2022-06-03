// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        if(n==0) return "";
        if(n==1) return "1";
        string ans = "1";
        
        int j = 1;
        
        while(j<n){
            
            string temp = "";
            for(int i=0;i<ans.length();i++){
                int count = 1;
                while(ans[i]==ans[i+1] and i+1 < ans.size()){
                    count++;
                    i++;
                }
                
                temp += to_string(count);
                temp += ans[i];
                
        
            }
            
            ans = temp;
            j++;
            
        }
        
        return ans;
    }   
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends