class Solution {
public: 
    int n ;
    string stoneGameIII(vector<int>& stoneValue) { 
        n=stoneValue.size();
        vector<int>dp(n,-1);
        int ans=solve(stoneValue ,0,dp);
        if(ans>0) return "Alice";
        else if( ans<0) return "Bob";
        return "Tie";
    }
    int solve(vector<int>&stoneValue ,int idx ,vector<int>&dp){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx]; 
        int sum=0; 
        int ans=INT_MIN;
        for(int i=idx;i< min(n,idx+3) ;i++){
            sum+=stoneValue[i];
            ans=max(ans ,sum-solve(stoneValue ,i+1,dp));
        }
        return dp[idx]=ans;
    }
};