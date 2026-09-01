class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            auto e=edges[i];
            adj[e[0]].push_back({e[1],succProb[i]});
            adj[e[1]].push_back({e[0],succProb[i]});
        }
        vector<double>dp(n,0);
        priority_queue<pair<double,int>>pq;
        pq.push({1,start_node});
        dp[start_node]=1;
        while(!pq.empty()){
            auto [dist,node]=pq.top();
            pq.pop();
            if(node==end_node){
                return dist;
            }
            for(auto [v,wt]:adj[node]){
                double new_dist=dist*wt;
                if(dp[v]<new_dist){
                    dp[v]=new_dist;
                    pq.push({dp[v],v});
                }
            }
        }
        return 0;
    }
};