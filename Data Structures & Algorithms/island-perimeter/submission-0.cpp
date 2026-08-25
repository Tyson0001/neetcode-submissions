class Solution {
public:
    int m,n;
    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    return dfs(grid,vis,i,j);
                }
            }
        }
        return -1;
    } 
    int dir[4]={0,0,-1,1};
    int dic[4]={1,-1,0,0};
    int dfs(vector<vector<int>>&grid ,vector<vector<int>>&vis ,int row ,int col){
        vis[row][col]=1;
        int cnt=0;
        for(int i=0;i<4;i++){
            int x=row+dir[i] ,y=col+dic[i];
            if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==0){
                cnt++;
                continue;
            }
            if(!vis[x][y] && grid[x][y]==1) cnt+=dfs(grid,vis,x,y);

        }
        return cnt;
    }
};