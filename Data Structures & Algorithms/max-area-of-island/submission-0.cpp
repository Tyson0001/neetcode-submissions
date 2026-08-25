class Solution {
public: 
    int m,n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }  
    int dir[4]={0,0,-1,1};
    int dic[4]={1,-1,0,0};
    int dfs(vector<vector<int>>&grid ,int row ,int col){
        grid[row][col]=0;
        int ans=1;
        for(int i=0;i<4;i++){
            int x=row+dir[i],y=col+dic[i];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                ans+=dfs(grid,x,y);
            }
        }
        return ans;
    }
};
