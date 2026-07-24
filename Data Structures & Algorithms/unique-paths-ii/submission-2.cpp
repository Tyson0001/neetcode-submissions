class Solution {
public: 
    int n,m;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->m=obstacleGrid.size() ,this->n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1)); 
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        return solve(obstacleGrid ,0,0,dp);
    }
    int solve(vector<vector<int>>&obstacleGrid ,int row ,int col ,vector<vector<int>>&dp){
        if(row==m-1 && col==n-1) return 1;
        if(row>=m || col>=n) return 0;
        if(obstacleGrid[row][col]==1) return 0;
        
        if(dp[row][col] !=-1) return dp[row][col];
        int right=solve(obstacleGrid ,row+1,col,dp);
        int bottom=solve(obstacleGrid,row,col+1,dp);
        return dp[row][col]=right+bottom;
    }
};