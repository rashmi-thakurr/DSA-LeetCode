// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee. 
            int patLen = pat.length();
            int txtLen = txt.length();
            vector<int> z;
            string new_string = pat + "#" + txt;
            int i=0;
            while(i<new_string.length()){
                if(i<=patLen){
                    z.push_back(0);
                }
                else{
                    int a = 0;
                    int b = i;
                    if(new_string[a]==new_string[i]){
                        while(new_string[a]==new_string[b] and b<new_string.length()){
                            a++;
                            b++;
                        }
                    }
                    z.push_back(a);
                }
                i++;
            }
            vector<int> ans;
            for(int i=0;i<new_string.length();i++){
                if(z[i]==patLen) ans.push_back(i-patLen);
            }
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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}

  // } Driver Code Ends