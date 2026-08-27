class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q; 
        int dir[8]={0,0,-1,-1,1,1};
        int dic[8]={-1,1,0,-1,0,1};
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        dist[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            if(row==n-1 && col==n-1) return dist[n-1][n-1];
            for(int k=0;k<8;k++){
                int x=row+dir[k],y=col+dic[k];
                if(x>=0 && x<n && y>=0 && y<n && !grid[x][y]){
                    if(dist[row][col]+1 <dist[x][y]){
                        dist[x][y]=dist[row][col]+1;
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};