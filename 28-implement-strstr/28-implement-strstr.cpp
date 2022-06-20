class Solution {
public:
    int calculate_hash(string s){
        if(s.length()==0) return 0;
        int n = s.length();
        long long int mod = 1000000007;
        long long int hash = 0;
        for(int i=0;i<n;i++){
            hash = (hash*29 + (s[i]-'a'+1))%mod;
        }
        return hash;
    }
    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        int n = haystack.length();
        int m = needle.length();
        long long need_hash = calculate_hash(needle);
        long long int mod = 1000000007;
        long long int p = 1;
        long long int hash = 0;
        
        for(int i=0;i<m-1;i++)p=(p*29)%mod;
        
        for(int i=0;i<n-m+1;i++){
            if(i==0){
                hash = calculate_hash(haystack.substr(i,m));
            }
            else {
                hash = ( (29*(hash-(haystack[i-1]-'a'+1)*p % mod)) % mod
                        + (haystack[i+m-1]-'a'+1) ) % mod;
                if(hash <0) hash = hash + mod;
            }
            
            if(need_hash == hash){
                if(haystack.substr(i,m) == needle) return i;
            }
        }
        
        return -1;
        
    }
};