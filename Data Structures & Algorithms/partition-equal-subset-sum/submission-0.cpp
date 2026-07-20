class Solution {
public: 
    int n;
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin() ,nums.end(),0);
        if(total%2!=0) return false;
        int target=total/2; 
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        sort(nums.begin() ,nums.end(),greater());
        return solve(nums,0,target,dp);
    }
    bool solve(vector<int>&nums ,int idx ,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(idx==n) return false; 
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool not_take=solve(nums,idx+1,target,dp); 
        
        bool take=false; 
        if(target >=nums[idx]){
            take=solve(nums,idx+1,target-nums[idx],dp);
            
        }
        return dp[idx][target]=take||not_take;
    } 
};
