class Solution {
public: 
    vector<int>dp;
    int rob(vector<int>& nums) { 
        int n=nums.size();
        dp.assign(n,-1);
        return solve(nums ,0);
    }
    int solve(vector<int>&nums ,int idx){
        if(idx>=nums.size()) return 0 ; 
        if(dp[idx]!=-1) return dp[idx];
        int not_Take=solve(nums,idx+1);
        int take=nums[idx] +solve(nums,idx+2);
        return dp[idx]=max(not_Take ,take);


    }
};
