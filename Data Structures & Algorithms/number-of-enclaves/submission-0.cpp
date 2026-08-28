class Solution {
public: 
    int m,n;
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int total=0;
        int ans=0; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) total++; 
                if(vis[i][j]) continue;
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j]==0) continue;
                    ans+=dfs(i,j,grid,vis);

                }
            }
        }
        return total-ans;
    } 
    int dir[4]={0,0,-1,1};
    int dic[4]={-1,1,0,0};
    int dfs(int row,int col ,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[row][col]=1;
        int ans=0;
        for(int i=0;i<4;i++){
            int x=row+dir[i],y=col+dic[i];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1 && !vis[x][y]){
                ans+=dfs(x,y,grid,vis);
            }
        }
        return ans+1;
    }
};