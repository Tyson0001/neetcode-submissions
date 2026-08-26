class Solution {
public: 
    int m,n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(),n=heights[0].size();
        vector<vector<int>>pac(m,vector<int>(n,0));
        vector<vector<int>>alt(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dfs(heights,alt,i,n-1);
            dfs(heights,pac,i,0);
        }
        for(int i=0;i<n;i++){
            dfs(heights,alt,m-1,i);
            dfs(heights,pac,0,i);
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j]==1 && alt[i][j]==1){
                    ans.push_back(vector<int>({i,j}));
                }
            }
        }
        return ans;
    }
    int dir[4]={0,0,-1,1};
    int dic[4]={-1,1,0,0};
    void dfs(vector<vector<int>>&heights,vector<vector<int>>&ocean,int row,int col){
        ocean[row][col]=1;
        for(int i=0;i<4;i++){
            int x=row+dir[i],y=col+dic[i];
            if(x>=0 && x<m && y>=0 && y<n && !ocean[x][y] && heights[row][col]<=heights[x][y]){
                dfs(heights,ocean,x,y);
            }
        }
    }
};
