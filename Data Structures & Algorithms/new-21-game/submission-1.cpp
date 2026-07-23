class Solution {
public: 
    vector<double>dp;
    double new21Game(int n, int k, int maxPts) {
        dp.resize(k,-1.0);
        return solve(n,k,0,maxPts);
    }
    double solve(int n ,int  k,int score ,int maxPts){
        if(score>=k){
            return (score<=n)?1.0:0.0;
        }
        if(dp[score]!=-1.0) return dp[score] ;
        double prob=0.0;
        for(int i=1;i<=maxPts ;i++){
            prob+=solve(n,k,score+i,maxPts);
        }
        return dp[score]=(prob)/maxPts;
    }
};