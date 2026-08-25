class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int ,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) q.push({0,{i,j}});
            }
        } 
        int dir[4]={0,0,1,-1};
        int dic[4]={1,-1,0,0};
        while(!q.empty()){
            auto node=q.front();
            q.pop();

            int steps=node.first,row=node.second.first ,col=node.second.second;
            
            for(int i=0;i<4;i++){
                int x=row+dir[i] ,y=col+dic[i];
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]!=-1 && steps+1 <grid[x][y]){
                    grid[x][y]=steps+1;
                    q.push({steps+1,{x,y}});
                }
            }
        }
    }
};
