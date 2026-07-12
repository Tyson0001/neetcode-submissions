class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        dfs(ans,nums,target,(int)nums.size()-1, temp);
        return ans;

    }
    void dfs(vector<vector<int>>&ans ,vector<int>&nums ,int target , int idx, vector<int>temp){
        if(idx<0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        dfs(ans,nums,target,idx-1,temp);
        if(target >=nums[idx]){
            temp.push_back(nums[idx]);
            dfs(ans,nums,target-nums[idx],idx,temp);
        }
    }
};
