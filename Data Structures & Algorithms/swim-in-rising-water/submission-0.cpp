class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],{0,0}});
        int dir[4]={0,0,-1,1};
        int dic[4]={-1,1,0,0};
        while(!pq.empty()){
            auto node =pq.top();
            pq.pop();
            int d=node.first,row=node.second.first,col=node.second.second;
            if(row==m-1 && col==n-1) return d;
            for(int i=0;i<4;i++){
                int x=row+dir[i],y=col+dic[i];
                if(x>=0 && x<m && y>=0 && y<n ){
                    int new_time =max(d,grid[x][y]);
                    if(dist[x][y] >new_time){
                        dist[x][y]=new_time;
                        pq.push({new_time ,{x,y}});
                    }
                }

            }
        }
        return -1;
    }
};
