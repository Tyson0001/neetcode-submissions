class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size() ,n=matrix[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0)); 
        int ans=0;
        for(int i=0;i<m;i++){
            vis[i][0]=matrix[i][0]-'0';
            ans=max(vis[i][0],ans);
        }
        for(int i=0;i<n;i++){
            vis[0][i]=matrix[0][i]-'0';
            ans=max(vis[0][i],ans);
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='0') continue;
                int up=vis[i-1][j];
                int dia=vis[i-1][j-1];
                int left=vis[i][j-1];
                if(up==0 || dia==0|| left==0){
                    vis[i][j]=1;
                }
                else vis[i][j]=min({left,dia,up})+1;
                ans=max(ans,vis[i][j]);
            }
        }
        return ans*ans;
    }
};