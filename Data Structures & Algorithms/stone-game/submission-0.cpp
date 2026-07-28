class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(piles,0,n-1,dp);
    }
    int solve(vector<int>&piles ,int i ,int  j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j) return piles[i];
        if(dp[i][j] !=-1) return dp[i][j];
        int take=piles[i] -solve(piles,i+1,j,dp);
        int not_take =piles[j]-solve(piles,i,j-1,dp);
        return dp[i][j]=max(take,not_take);
    }
};