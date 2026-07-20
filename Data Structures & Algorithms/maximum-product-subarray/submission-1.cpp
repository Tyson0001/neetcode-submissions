class Solution {
public: 
    int  n;
    int maxProduct(vector<int>& nums) {
        n=nums.size(); 
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
    int solve(vector<int>&nums ,int idx,vector<int>&dp){
        if(idx==n) return INT_MIN; 
        if(dp[idx]!=-1) return dp[idx];
        int prod=1; 
        int ans=INT_MIN;
        for(int i=idx;i<n;i++){
            prod*=nums[i];
            int temp =max(prod,solve(nums,i+1,dp));
            ans=max(ans,temp);
            
            
        }
        return dp[idx]=ans;
    }
};
