class Solution {
public: 
    int n;
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        n=nums.size(); 
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(nums ,1,n-2 ,dp);
    }
    int solve(vector<int>&nums ,int start ,int end ,vector<vector<int>>&dp){
        if(start>end){
            return 0;
        }  
        if(dp[start][end]!=-1) return dp[start][end];
        int maxi=INT_MIN;
        for(int k=start;k<=end;k++){
            int steps=nums[start-1]*nums[k]*nums[end+1] + solve(nums,start,k-1,dp)+solve(nums,k+1,end,dp); 
            maxi=max(maxi,steps);
        }
        return dp[start][end]=maxi;
    }
};
