class DS{
public:
    vector<int>parent;
    vector<int>rank;
    DS(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    void joint(int u ,int v){
        int pu=find(u), pv=find(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv])parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else parent[pv]=pu, rank[pu]++;
    }
};
class Solution {
public: 
    int n;
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        DS ds(n*n); 
        int dir[4]={0,0,-1,1};
        int dic[4]={1,-1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int x=i+dir[k],y=j+dic[k];
                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
                        ds.joint(i*n+j ,x*n+y);
                    }
                }
            }
        }
        int island=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    island=ds.find(i*n+j);
                }
            }
        }
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                for(int k=0;k<4;k++){
                    int x=i+dir[k],y=j+dic[k];
                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1 && island==ds.find(x*n+y)){
                        dist[i][j]=0;
                        q.push({island,{i,j}});
                    }
                }
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int parent=node.first,row=node.second.first,col=node.second.second;
            if( grid[row][col]==1){
                if(parent!=ds.find(row*n+col)) return dist[row][col];
                else continue;
            }
            for(int i=0;i<4;i++){
                int x=row+dir[i], y=col+dic[i];
                if(x>=0 && x<n && y>=0 && y<n && dist[row][col]+1 <dist[x][y]){
                    dist[x][y]=dist[row][col]+1;
                    q.push({parent,{x,y}});
                }
            }
        }
        return -1;

    }
};