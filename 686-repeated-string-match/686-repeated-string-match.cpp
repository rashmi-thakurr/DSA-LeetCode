class Solution {
public:
    long long int calculate_hash(string s){
        if(s.length()==0) return 0;
        long long int mod = 1000000007;
        long long int hash=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            hash = (hash*31 + (s[i]-'a'+1))%mod;
        }
        return hash;
    }
    bool patternMatch(string pat, string s){
        if(pat.length()>s.length()) return false;
        long long int mod = 1000000007;
        int m = pat.length();
        int n = s.length();
        long long int pat_hash = calculate_hash(pat);
        long long int h = 1;
        for(int i=0;i<m-1;i++){
            h = (h*31) % mod;
        }
        long long int hash=0;
        for(int i=0;i<n-m+1;i++){
            if(i==0){
                hash = calculate_hash(s.substr(i,m));
            }
            else 
            {
                hash = ((31*(hash-(s[i-1]-'a'+1)*h%mod))%mod + (s[i+m-1]-'a'+1))%mod;

                if(hash < 0) hash = hash + mod;
            }
             // cout<<i<<" "<<hash<<" "<<pat_hash<<endl;   
            
            if(pat_hash == hash){
                if(s.substr(i,m) == pat) return true;
            }
        }
        
        return false;
    }
    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string s = A;
        while(s.size() < B.size()){
            count++;
            s+=A;
        }
        if(s == B) return count;
        if(patternMatch(B,s)) return count;
        if(patternMatch(B,s+A)) return count+1;
        return -1;
        
    }
};