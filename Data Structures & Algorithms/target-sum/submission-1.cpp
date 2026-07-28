class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=accumulate(nums.begin() ,nums.end(),0);
        if((total+target)%2!=0) return 0;
        target =(total+target)/2;
       
        vector<vector<int>>dp(nums.size() ,vector<int>(target+1,-1)); 
        
        return solve(nums,target,0,dp);
    }
    int solve(vector<int>&nums ,int target ,int idx, vector<vector<int>>&dp){
        if(idx==nums.size()){
            if(target==0) return 1;
            return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int not_take=solve(nums,target,idx+1,dp); 
        int take=0;
        if(target>=nums[idx]){
            take+=solve(nums,target-nums[idx],idx+1,dp);
        } 
        return dp[idx][target]=take+not_take;
    }
};
