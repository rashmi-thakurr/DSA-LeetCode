class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        if(n==1) return true;
        
        unordered_map<int,vector<int>> graph;
        
       for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n,false);
        
        stack<int> s;
        
        s.push(start);
        
        visited[start] = true;
        
        while(!s.empty()){
            int curr = s.top();
            visited[curr] = true;
            if(curr==end)
                return true;
            s.pop();
            
            for(auto i:graph[curr]){
                if(!visited[i]){
                    visited[i]=true;
                    s.push(i);
                }
            }
           
        }
        
        return false;
    }
};