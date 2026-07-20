class Solution {
public: 
    int n;
    vector<int>costs;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        this->costs=costs; 
        vector<vector<int>>dp(n,vector<int>(400,-1));

        return solve(days,0,0,dp);
    }
    int solve(vector<int>&days ,int idx ,int vaild,vector<vector<int>>&dp){
        if(idx==n) return 0;  
        if(dp[idx][vaild]!=-1) return dp[idx][vaild];
        int not_take=INT_MAX;
        if(vaild>=days[idx]) not_take=solve(days,idx+1,vaild,dp);
        int take1=costs[0]+solve(days,idx+1,days[idx],dp);
        int take7=costs[1]+solve(days,idx+1,days[idx]+6,dp);
        int take30=costs[2]+solve(days,idx+1,days[idx]+29 ,dp);
        return dp[idx][vaild]=min({not_take,take1,take7,take30});
    }
};