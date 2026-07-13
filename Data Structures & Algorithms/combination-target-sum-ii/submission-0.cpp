class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        int idx=(int)candidates.size()-1;
        dfs(candidates,target,idx,temp,ans);
        return ans;
    }
    void dfs(vector<int>&candidates,int target ,int idx,vector<int>temp,vector<vector<int>>&ans){
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx<0) return;
        
        
        if(target>=candidates[idx]){
            temp.push_back(candidates[idx]);
            dfs(candidates,target-candidates[idx],idx-1,temp,ans);
            temp.pop_back();
            
        }
        while(idx>0 && candidates[idx]==candidates[idx-1])idx--;
        dfs(candidates,target,idx-1,temp,ans);
    }
};
