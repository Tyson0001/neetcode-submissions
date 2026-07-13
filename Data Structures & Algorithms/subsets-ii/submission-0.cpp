class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        dfs(ans,temp,nums,n-1);
        return ans;
    }
    void dfs(vector<vector<int>>&ans, vector<int>temp,vector<int>&nums,int idx){
        if(idx<0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        dfs(ans,temp,nums,idx-1);
        temp.pop_back();
        while(idx>0 && nums[idx]==nums[idx-1])idx--;
        dfs(ans,temp,nums,idx-1);
    }
};
