class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(ans,temp,n,k);
        return ans;
    }
    void dfs(vector<vector<int>>&ans, vector<int>temp,int idx,int k){
        if(k==0){
            ans.push_back(temp);
            return ;
        }
        
        
        for(int i=idx;i>=1;i--){ 
            temp.push_back(i);
            dfs(ans,temp,i-1,k-1);
            temp.pop_back();
        }
    }
};