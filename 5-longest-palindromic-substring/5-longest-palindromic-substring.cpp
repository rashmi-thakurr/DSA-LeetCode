class Solution {
public:
     int longestPalindromeSize(string s,int left, int right){
        
        if(left>right) return 0;
        
        while((left >=0) && (right<s.length()) && (s[left]==s[right])){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome (string S) {
        // code here
        
        int start = 0;
        int end = 0;
        for(int i=0;i<S.length();i++){
            int len1 = longestPalindromeSize(S,i,i);
            int len2 = longestPalindromeSize(S,i,i+1);
            int len = max(len1,len2);
            if(len > end - start){
                start = i - ((len - 1)/2);
                end = i + (len)/2;
            }
        }
      return S.substr(start,end-start+1);
    }
};