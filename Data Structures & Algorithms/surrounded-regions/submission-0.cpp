class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j]=='X') continue;
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int dir[4]={0,0,-1,1};
        int dic[4]={-1,1,0,0};
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first ,col=node.second;
            for(int i=0;i<4;i++){
                int x=row+dir[i],y=col+dic[i];
                if(x>=0 && x<m && y>=0 && y<n && !vis[x][y] && board[x][y]=='O'){
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0) board[i][j]='X';
            }
        }
    }
};
