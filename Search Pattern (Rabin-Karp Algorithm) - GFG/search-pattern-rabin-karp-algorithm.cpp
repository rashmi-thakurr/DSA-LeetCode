// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        
        
        long long int calculate_hash(string s){
            long long int mod =  1000000007 ;
            if(s.length()==0) return 0;
            long long int hash = 0;
            for(int i=0;i<s.length();i++){
                hash = (hash*31 + (s[i]-'a'+1)) % mod;
            }
            return hash;
        }
        
       
    
        vector <int> search(string pat, string s)
        {
            //code here.
           long long int mod =  1000000007 ;
            vector<int> ans;
            int m = pat.length();
            int n = s.length();
            long long int h=1;
            for (int i = 0; i < m - 1; i++) 
                h = (h * 31) % mod; 

            
            long long int hash = 0;
            long long int pat_hash = calculate_hash(pat);
            
            for(int i=0;i<n-m+1;i++){
                if(i==0){
                    hash = calculate_hash(s.substr(i,m));
                }
                else{
                    hash = ((31*(hash - (s[i-1]-'a'+1)*+h%mod))%mod + s[i+m-1]-'a'+1)%mod; 
                    if (hash < 0) 
                        hash = (hash + mod); 
                }
                // cout<<hash<<" "<<pat_hash<<endl;
                if(hash == pat_hash){
                    if(s.substr(i,m)==pat) ans.push_back(i+1);
                }
            }
           if(ans.size()==0) ans.push_back(-1);
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends