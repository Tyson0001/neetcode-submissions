#include <cstring>
class Solution {
public: 
    int n; 
    int dp[51][51][51];
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size() ;
        memset(dp,-1,sizeof(dp));
        int ans =solve(grid ,0,0,0);
        return (ans==INT_MIN)?0:ans;
    }
    int solve(vector<vector<int>>&grid ,int r1 ,int c1,int r2){
        int c2=r1+c1-r2;
        if(c2>=n || r1>=n || r2>=n || c1>=n ) return INT_MIN; 
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(r1==n-1 && c1==n-1 && r2==n-1) return grid[r1][c1]; 
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
        int ans=0;
        if(r1!=r2 || c1!=c2){
            ans+=grid[r1][c1] +grid[r2][c2];
        }else ans+=grid[r1][c1];
        int take=solve(grid,r1+1,c1,r2+1);
        take =max(take ,solve(grid ,r1+1,c1,r2));
        take =max(take ,solve(grid,r1,c1+1 ,r2+1));
        take=max(take ,solve(grid,r1,c1+1,r2)); 
        if(take==INT_MIN) return dp[r1][c1][r2]=take;
        return dp[r1][c1][r2]=take+ans;
    }
};