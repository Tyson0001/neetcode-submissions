class Solution {
public: 
    int n;
    bool splitArraySameAverage(vector<int>& nums) {
        n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0); 
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n/2+1 ,vector<int>(total+1 ,-1)));
        for(int cnt=1 ;cnt<=(n/2) ;cnt++){ 
            if((total*cnt)%n!=0) continue;
            int target = (total*cnt)/n;
            if(solve(nums,target ,cnt,0,dp)) return true;
        }
        return false;
    }
    bool solve(vector<int>&nums ,int target ,int cnt ,int idx,vector<vector<vector<int>>>&dp){ 
        if(cnt==0 )  return target==0;
        if(idx==n|| target <0 || cnt<0) return false; 
        if(dp[idx][cnt][target]!=-1) return dp[idx][cnt][target];
        bool not_take =solve(nums,target ,cnt , idx+1,dp);
        bool take=false;
        if(target >=nums[idx] && cnt>0){
            take =solve(nums ,target-nums[idx] ,cnt-1 ,idx+1,dp);
        }
        return dp[idx][cnt][target]=take || not_take ;
    }
};