class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        
        dfs(ans,nums,(int)nums.size()-1);
        return ans;
    }
    void dfs(vector<vector<int>>&ans, vector<int>&nums ,int idx){
        if(idx<0){
            ans.push_back(nums);
            return;
        } 
        unordered_set<int>st;
        for(int i=idx;i>=0;i--){
            if(st.count(nums[i])) continue;
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            dfs(ans,nums,idx-1);
            swap(nums[i],nums[idx]);
        }
    }
};