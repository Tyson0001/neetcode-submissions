#include <cstring>
class Solution {
public:
    int n ;
    int dp[51][51][51];
    
    int solve(vector<vector<int>>&grid,int r1 ,int c1 ,int r2){
        int c2=r1+c1-r2;
        if(r1<0||r1>=n||c1<0||c1>=n || r2<0||r2>=n||c2<0||c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        if(r1==n-1 && c1==n-1 && r2==n-1){
            return grid[r1][c1];
        } 
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
        int take=0;
        if(r1==r2 && c1==c2){
            take+=grid[r1][c1];
        }else take+=grid[r1][c1]+grid[r2][c2]; 
        int maxi=solve(grid,r1+1,c1,r2+1);
        maxi=max(maxi,solve(grid,r1+1,c1,r2));
        maxi=max(maxi,solve(grid,r1,c1+1,r2));
        maxi=max(maxi,solve(grid,r1,c1+1,r2+1));
        return dp[r1][c1][r2]=take+maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(grid,0,0,0);
        return max(0,ans);
    }
};