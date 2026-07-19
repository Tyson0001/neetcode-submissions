class Solution {
public: 
    vector<int>dp;
    int rob(vector<int>& nums) {
        int n=nums.size();  
        vector<vector<int>>dp(n,vector<int>(2,-1));
        if(n==1) return nums[0];
        if(n==2) return max(nums[0] ,nums[1]);
        return max(solve(nums,0,dp,1) ,solve(nums,1,dp,0));
    }
    int solve(vector<int>&nums ,int idx ,vector<vector<int>>&dp , int flag){
        if(idx>=nums.size() || (flag==1 && idx==nums.size()-1)){
            return 0;
        }  
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        int not_take=solve(nums,idx+1,dp,flag);
        int take=nums[idx]+solve(nums,idx+2,dp,flag);
        return dp[idx][flag]= max(not_take ,take);
    }
};
