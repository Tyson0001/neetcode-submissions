class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        bool ans=solve(0,-1,adj,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return ans;
    }
    bool solve(int node , int parent ,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        bool a=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                a=  a && solve(it,node,adj,vis);
            }else if( vis[it] && it!=parent) return false;
        }
        return a;
    }
};
