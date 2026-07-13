class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(ans,temp,nums);
        return ans;
    }
    void dfs(vector<vector<int>>&ans, vector<int>temp,vector<int>nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==-11)continue;
            temp.push_back(nums[i]);
            int store=nums[i];
            nums[i]=-11;
            dfs(ans,temp,nums);
            nums[i]=store;
            
            temp.pop_back();
        }
    }
};
