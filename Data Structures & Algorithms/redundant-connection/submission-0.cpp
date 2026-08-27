class Solution {
public: 
    int timer=0;
    set<pair<int,int>>ans;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n+1,0);
        vector<int>tin(n+1,-1),low(n+1,-1);
        dfs(adj,vis,tin,low,1,-1);
        
        vector<int>res;
        for(int i=n-1;i>=0;i--){
            auto e=edges[i];
            if(!ans.count({e[0],e[1]}) && !ans.count({e[1],e[0]})) return e;
        }
        return res;

    } 
    void dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&tin,vector<int>&low,int node,int parent){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto it:adj[node]){ 
            if(parent==it) continue;
            if(!vis[it]){
                dfs(adj,vis,tin,low,it,node);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    ans.insert({node,it});
                }
            }else low[node]=min(low[node],low[it]);
        }
    }
};
