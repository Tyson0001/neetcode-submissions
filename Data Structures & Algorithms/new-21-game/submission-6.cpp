class Solution {
public:
    double new21Game(int n, int k, int maxPts) { 
        vector<double>dp(k+maxPts,-1.0);
        return solve(n,k,0,maxPts ,dp);
    }
    double solve(int n ,int k,int score ,int maxPts ,vector<double>&dp){
        if(score==k-1){
            return (double)(min(n-k+1 ,maxPts))/(double)maxPts; 

        } 
        if(score>=k){
            return (score<=n)?1.0:0.0;

        } 
        if(dp[score]!=-1 ) return dp[score];
        dp[score]=solve(n,k,score+1,maxPts,dp);
        dp[score]-=(solve(n,k,score+1+maxPts,maxPts,dp) -solve(n,k,score+1,maxPts,dp))/(double)maxPts;
        return dp[score];
    }
};