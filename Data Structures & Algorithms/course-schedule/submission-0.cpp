class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return ans==n;

    }
};
