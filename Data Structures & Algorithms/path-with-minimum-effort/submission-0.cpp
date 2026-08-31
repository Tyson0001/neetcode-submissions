class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int dir[4]={0,0,-1,1};
        int dic[4]={-1,1,0,0};
        while(!pq.empty()){
            auto node =pq.top();
            pq.pop();

            int dist=node.first,row=node.second.first ,col=node.second.second;
            if(row==n-1 && col==m-1) continue;
            for(int i=0;i<4;i++){
                int  x=row+dir[i],y=col+dic[i];
                if(x>=0 && x<n && y>=0 && y<m){
                    int effort=max(dist,abs(heights[row][col]-heights[x][y]));
                    if(effort < dp[x][y]){
                        dp[x][y]=effort;
                        pq.push({dp[x][y] ,{x,y}});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};