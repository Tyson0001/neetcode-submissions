class Solution {
public: 
    int n ,m;
    int minPathSum(vector<vector<int>>& grid) {
        this->m=grid.size() ,this->n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,0,0,dp);
    }
    int solve(vector<vector<int>>&grid ,int row ,int col ,vector<vector<int>>&dp){
        if(row==m-1 && col==n-1) return grid[row][col];
        if(row>=m || col >=n) return INT_MAX;
        if(dp[row][col]!=-1) return dp[row][col];
        int right=solve(grid,row,col+1,dp);
        int bottom=solve(grid,row+1,col,dp);
        return dp[row][col]=min(right,bottom) +grid[row][col];
    }
};