class Solution {
public: 
    int m,n;
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0; 
        m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    } 
    int dir[4]={0,0,-1,1};

    int dic[4]={-1,1,0,0};
    void dfs(vector<vector<char>>&grid , int row ,int col){
        grid[row][col]='0';
        for(int i=0;i<4;i++){
            int x=row+dir[i],y=col+dic[i];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1'){
                dfs(grid,x,y);
            }
        }
    }
};
