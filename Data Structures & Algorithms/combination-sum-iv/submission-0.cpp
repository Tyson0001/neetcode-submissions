class Solution {
public: 
    int n;
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size(); 
        vector<int>dp(target+1,-1);
        return solve(target,nums,dp);
    }
    int solve(int target  ,vector<int>&nums ,vector<int>&dp){ 
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int take=0;
        for(int i=0;i<n;i++){
            if(target <nums[i]) continue;
            take+=solve(target-nums[i],nums,dp);
        }
        
        return dp[target]=take;

    }
};