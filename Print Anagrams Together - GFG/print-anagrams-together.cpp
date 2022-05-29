// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  bool isAnagram(string a, string b){
      
      if(a.length()!=b.length()) return false;
      
      int n = a.length();
      unordered_map<char,int> mp;
      for(int i=0;i<n;i++){
         mp[a[i]]++;
         mp[b[i]]--;
      }
      
      unordered_map<char,int>::iterator itr;
      
      for(auto itr=mp.begin();itr!=mp.end();itr++){
          if((*itr).second != 0) return false;
      }
      
      return true;
      
  }
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        int n = string_list.size();
        vector<int> mp(n,0);
       
        for(int i=0;i<n;i++){
            if(mp[i]==1){
                continue;
            }
            vector<string> v;
            v.push_back(string_list[i]);
            mp[i]=1;
           
            for(int j=i+1;j<n;j++){
                if(isAnagram(string_list[i],string_list[j]) and mp[j]==0){
                    v.push_back(string_list[j]);
                    mp[j]=1;
                    
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends