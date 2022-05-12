#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class compare{
    public:
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
        if(a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    }
};
int main()
 {
     int t;
     cin>>t;
     while(t--){
         int n;
         cin>>n;
         vector<int> arr;
         for(int i=0;i<n;i++){
             int x;
             cin>>x;
             arr.push_back(x);
         }
         
         unordered_map<int,int> mp;
         
         
         for(auto i:arr){
             mp[i]++;
         }
         
         priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
         
         for(auto it=mp.begin();it!=mp.end();it++){
           pq.push({it->second,it->first});  
         }
         
         vector<int> ans;
         
         while(!pq.empty()){
             int f = pq.top().first;
             int v = pq.top().second;
             
             while(f--){
                 ans.push_back(v);
             }
             
             pq.pop();
         }
         
          for(auto i:ans){
            cout<<i<<" ";
         }
         
         cout<<endl;
         
     }
	return 0;
}