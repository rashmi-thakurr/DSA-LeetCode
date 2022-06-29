class Solution {
public:
    bool checkDfs(vector<vector<int>>&graph, vector<int> &color, int i){
        if(color[i]==-1) color[i]=1;
        for(auto it:graph[i]){
            if(color[it]==-1){
                color[it]=!color[i];
                if(!checkDfs(graph,color,it)) return false;
            }
            else if(color[it]==color[i]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n+1,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!checkDfs(graph,color,i)) return false;
            }
        }
        return true;
    }
    
};