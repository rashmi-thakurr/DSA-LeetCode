class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        
        queue<int> q;
        
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(cnt==numCourses) return true;
        return false;
    }
};