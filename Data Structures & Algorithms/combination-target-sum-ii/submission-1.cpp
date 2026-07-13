class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int>temp;
        dfs(ans,candidates, target,n-1,temp);
        return ans;
    }
    void dfs(vector<vector<int>>&ans,vector<int>&candidates,int target , int idx,vector<int>temp){
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx<0) return;
        
        if(target>=candidates[idx]){
            temp.push_back(candidates[idx]);
            dfs(ans,candidates,target-candidates[idx],idx-1,temp);
            temp.pop_back();
        }
        while(idx>0 && candidates[idx]==candidates[idx-1]) idx--;
        dfs(ans,candidates,target,idx-1,temp);
    }
};
