class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>root(n,0);
        for(int i=0;i<n;i++){
            root[i]=dfs(i,-1,adj);
        }
        int mini=*min_element(root.begin(),root.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mini==root[i]) ans.push_back(i);
        }
        return ans;
    }
    int dfs(int node,int parent,vector<vector<int>>&adj){
        int ans=1;
        int temp=0;
        for(int it:adj[node]){
            if(parent==it) continue;
            temp=max(temp,dfs(it,node,adj));
        }
        return ans+temp;
    }
};