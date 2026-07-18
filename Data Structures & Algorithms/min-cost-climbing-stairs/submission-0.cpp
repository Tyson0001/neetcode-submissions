class Solution {
public: 
    int n; 
    vector<int>dp;
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size(); 
        dp.assign(n,-1);
        return min(solve(0,cost) ,solve(1,cost));
    }
    int solve(int idx, vector<int>&cost){
        if(idx>=n) return 0; 
        if(dp[idx]!=-1) return dp[idx];
        int not_take=cost[idx]+solve(idx+1,cost);
        int take=cost[idx]+solve(idx+2,cost);
        return dp[idx]= min(not_take ,take);
    }
};
