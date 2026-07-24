class Solution {
public: 
    int n;
    int m;
    int uniquePaths(int m, int n) {
        this->m=m ,this->n=n;
        vector<vector<int>>vis(m,vector<int>(n,-1));
        return solve(vis,0,0);
    } 
    
    int solve(vector<vector<int>>&vis ,int row ,int col){
        
        if(row==m-1 && col==n-1) return 1;  
        if(row>=m || col>=n) return 0; 
        if(vis[row][col]!=-1) return vis[row][col];
        int right=solve(vis,row,col+1);
        int bottom=solve(vis,row+1,col);
       
        return vis[row][col]=right+bottom;
    }
};
