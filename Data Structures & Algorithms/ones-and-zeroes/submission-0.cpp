class Solution {
public: 
    int m ,n ,x; 
    vector<pair<int ,int>>prefix;
    int findMaxForm(vector<string>& strs, int m, int n) {
        this->m=m ,this->n=n;
        x=strs.size(); 
        for(int i=0;i<x;i++){
            string str=strs[i]; 
            int one=0 ,zero=0;
            for(auto c:str){
                if(c=='0') zero++;
                else one++;
            }
            prefix.push_back({one ,zero});
        } 
        vector<vector<vector<int>>>dp(x,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return solve(strs,0,0,0,dp);
    }
    int solve(vector<string>&strs ,int idx ,int one ,int zero,vector<vector<vector<int>>>&dp){
        if(one>n || zero>m) return INT_MIN;
        if(idx==x){
            if(one<=n && zero<=m ) return 0;
            return INT_MIN;
        } 
        if(dp[idx][one][zero]!=-1) return dp[idx][one][zero];
        auto c=prefix[idx];
        int not_take= solve(strs,idx+1,one,zero,dp); 
        int take=1+solve(strs,idx+1,one+c.first ,zero+c.second,dp);;
        
        return dp[idx][one][zero]=max(take,not_take);
    }
};