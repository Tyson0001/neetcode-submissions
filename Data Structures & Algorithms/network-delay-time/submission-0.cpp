class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dp(n+1,INT_MAX);
        vector<vector<pair<int ,int>>>adj(n+1);
        for(auto e:times){
            adj[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dp[k]=0;
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            for(auto [adnode,wt]:adj[node]){
               if(d+wt<dp[adnode]){
                dp[adnode]=d+wt;
                pq.push({dp[adnode],adnode});
               }
            }
        }
        int maxi=*max_element(dp.begin()+1,dp.end());
        if(maxi==INT_MAX) return -1;
        return maxi;
    }
};
