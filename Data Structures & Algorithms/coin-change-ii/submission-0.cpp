class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin() ,coins.end(),greater()); 
        vector<vector<int>>dp(coins.size()  ,vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp);

    }
    int solve(vector<int>&coins ,int amount ,int idx,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(idx==coins.size()){
            return 0;
        } 
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int not_take=solve(coins,amount,idx+1,dp);
        int take=0;
        if(amount >=coins[idx]) take+=solve(coins,amount-coins[idx],idx,dp);
        return dp[idx][amount]=take+not_take;
    }
};
