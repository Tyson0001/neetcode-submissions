class Solution {
public: 
    int n;
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<int>dp(n,-1);
        int ans=solve(stoneValue,0,dp);
        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        return "Tie";
    }
    int solve(vector<int>&stoneValue ,int idx,vector<int>&dp){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int maxscore=INT_MIN;
        int score=0;
        for(int i=idx ;i<min(idx+3,n);i++){
            score+=stoneValue[i];
            int opp=solve(stoneValue ,i+1,dp);
            maxscore=max(maxscore,score-opp);
        }
        return dp[idx]=maxscore;
    }
};