class Solution {
public:
    int m,n; 
    int org , color;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size(),n=image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        this->color=color;
        org=image[sr][sc];
        dfs(image,sr,sc,vis);
        return image;
    } 
    int dir[4]={0,0,-1,1};
    int dic[4]={1,-1,0,0};
    void dfs(vector<vector<int>>&image,int row ,int col ,vector<vector<int>>&vis){
        vis[row][col]=1;
        image[row][col]=color;
        for(int i=0;i<4;i++){
            int x=row+dir[i],y=col+dic[i];
            if(x>=0 && x<m && y>=0 && y<n && !vis[x][y] && image[x][y]==org){
                dfs(image,x,y,vis);
            }
        }
    }
};