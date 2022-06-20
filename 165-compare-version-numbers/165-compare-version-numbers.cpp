class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1==" " and version2==" ") return 0;
        if(version1==" ") return -1;
        if(version2==" ") return 1;
    
        
        int i=0;
        int j=0;
        
        while(i<version1.length() and j<version2.length()){
            string v1="";
            string v2="";
            while(version1[i]!='.' and  i<version1.length()){
                if(version1[i]-'0'>=0 and version1[i]-'0'<=9) v1+=version1[i];
                i++;
            }
            while(version2[j]!='.' and j<version2.length()){
                if(version2[j]-'0'>=0 and version2[j]-'0'<=9) v2+=version2[j];
                j++;
            }
            if(stoi(v1)==stoi(v2)){
                i++;
                j++;
                continue;
            }
            else if( stoi(v1) < stoi(v2)){
               return -1;
            }
            else{
                return 1;
            }
            i++;
            j++;
        }
        int ans = 0;
        while(i<version1.length()){
            string v1="";
             while(version1[i]!='.' and  i<version1.length()){
                if(version1[i]-'0'>=0 and version1[i]-'0'<=9) v1+=version1[i];
                i++;
            }
            if(stoi(v1)>0){
                ans = 1;
            }
            i++;
        }
         while(j<version2.length()){
            string v2="";
             while(version2[j]!='.' and  j<version2.length()){
                if(version2[j]-'0'>=0 and version2[j]-'0'<=9) v2+=version2[j];
                j++;
            }
             // cout<<stoi(v2)<<endl;
            if(stoi(v2)>0){
                // cout<<"idhar hu me"<<endl;
                ans = -1;
            }
            j++;
        }
        return ans;
        
    }
};