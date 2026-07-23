class Solution {
public: 
    vector<double>dp;
    double new21Game(int n, int k, int maxPts) {
        dp.resize(k+maxPts,-1.0);
        return solve(n,k,0,maxPts);
    }
    double solve(int n ,int  k,int score ,int maxPts){
        if(score==k-1){
            return min(n-k+1 ,maxPts)/(double)maxPts;
        }
        if(score>n) return 0.0; 
        if(score>=k){
            return 1.0;
        }
        
        if(dp[score]!=-1.0) return dp[score];
        dp[score]=solve(n,k,score+1,maxPts);
        dp[score]-=(solve(n,k,score+1+maxPts,maxPts)-solve(n,k,score+1,maxPts))/maxPts;
        return dp[score];
    }
};