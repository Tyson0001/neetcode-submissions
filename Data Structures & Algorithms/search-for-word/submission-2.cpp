class Solution {
public: 
    int n ,m;
    bool exist(vector<vector<char>>& board, string word) { 
        n=board.size() , m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,vis,word ,  i , j,1)) return true;
                }
            }
        }
        return false;
    } 
    int dir[4]={0,0,-1,1};
    int dic[4]={1,-1,0,0};
    bool dfs(vector<vector<char>>&board ,vector<vector<int>>&vis , string word, int i ,int j, int idx){
        vis[i][j]=1;
        if(idx==word.size()) return true;
        for(int k=0;k<4;k++){
            int row=i+dir[k] , col=j+dic[k];
            if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && word[idx]==board[row][col]){
                if(dfs(board,vis,word,row,col,idx+1)) return true;
            }
        } 
        vis[i][j]=0;
        return false;
    }
};
