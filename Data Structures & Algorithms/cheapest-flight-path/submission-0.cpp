class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            int steps=n.first,node=n.second.first,cost=n.second.second;
            if(steps>k) continue;
            for(auto [adnode,wt]:adj[node]){
                if(dist[adnode]>cost+wt){
                    dist[adnode]=cost+wt;
                    q.push({steps+1,{adnode,dist[adnode]}});
                }
            }
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];


    }
};
