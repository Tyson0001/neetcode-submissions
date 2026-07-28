class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        vector<vector<int>>dp(prices.size() ,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
    int solve(vector<int>&prices ,int idx ,int buy,vector<vector<int>>& dp){
        if(idx>=prices.size()){
            return 0;
        }  
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int take=0;
        if(buy){
           take=max(solve(prices,idx+1,1,dp) ,-prices[idx]+solve(prices,idx+1,0,dp));
        }
        else{
            take=max(solve(prices,idx+1,0,dp),prices[idx]+solve(prices,idx+2,1,dp));
        }
        return dp[idx][buy]=take;


    }

};
