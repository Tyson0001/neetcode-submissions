class Solution {
public: 
    int n;
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==0) continue;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                ans++;
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>&adj,vector<int>&vis,int node){
        vis[node]=1;
        for(int it:adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
};