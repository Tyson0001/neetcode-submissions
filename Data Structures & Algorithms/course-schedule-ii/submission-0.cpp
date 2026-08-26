class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return (ans.size()==n)?ans:vector<int>();
    }
};
