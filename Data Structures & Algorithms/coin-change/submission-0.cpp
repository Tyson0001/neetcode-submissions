class Solution {
public: 
    int n;
    int coinChange(vector<int>& coins, int amount) { 
        n=coins.size();  
        vector<vector<long long>>dp(n,vector<long long>(amount+1,-1));
        sort(coins.begin() ,coins.end(), greater());
        int ans= (int)solve(coins ,0,amount,dp);
        return (ans==INT_MAX)?-1:ans;
    }
    long long solve(vector<int>&coins ,int idx , int amount,vector<vector<long  long>>&dp){
        if(amount ==0) return 0;
        if(idx==n) return INT_MAX; 
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        long long not_Take = solve(coins,idx+1,amount,dp);
        long long take =INT_MAX;
        if(amount >=coins[idx]){
            take = solve(coins,idx ,amount-coins[idx],dp);
            if(take!=INT_MAX) take+=1;
        }
        return dp[idx][amount]=min(not_Take ,take);
    }
};
