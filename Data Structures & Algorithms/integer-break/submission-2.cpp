class Solution {
public:
    int integerBreak(int n) { 
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
    int solve(int n,vector<int>&dp){ 
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            int temp =i*max(n-i ,solve(n-i,dp));
            ans=max(ans,temp);
        }
        return dp[n]=ans;

    }
};