class Solution {
public: 
    int total;
    int n;
    int lastStoneWeightII(vector<int>& stones) {
        total=accumulate(stones.begin() ,stones.end(),0);
        n=stones.size();
        int target=(total+1)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(stones,0,0,target,dp);
    }
    int solve(vector<int>&stones ,int idx,int sum ,int target,vector<vector<int>>&dp){
        if(sum>=target || idx==n){
            return abs(2*sum-total);
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        return dp[idx][sum]=min(
            solve(stones,idx+1,sum+stones[idx],target,dp),
            solve(stones,idx+1,sum,target,dp)
        );
    }
};