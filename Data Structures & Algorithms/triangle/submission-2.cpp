class Solution {
public: 
    int n;
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        vector<vector<int>>dp;
        for(int i=0;i<n;i++){
            int m=triangle[i].size();
            vector<int>temp(m,-1e9);
            dp.push_back(temp);
        }
        return solve(triangle,0,0,dp);
    }
    int solve(vector<vector<int>>&triangle,int row ,int col ,vector<vector<int>>&dp){
        if(row==n) return 0; 
        if(dp[row][col]!=-1e9) return dp[row][col]; 
        int take = solve(triangle,row+1 ,col,dp);
        int not_take =INT_MAX;
        if(col <row+1){
            not_take=solve(triangle ,row+1,col+1,dp);
        } 
        
        return dp[row][col]=triangle[row][col] +min(take,not_take);
    }
};