class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(auto e:prerequisites){
            dp[e[0]][e[1]]=true;
        }
        for(int va=0;va<n;va++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dp[i][j]= (dp[i][j])||(dp[i][va] && dp[va][j]);
                }
            }
        }
        int m=queries.size();
        vector<bool>ans(m,false);
        for(int i=0;i<m;i++){
            ans[i]=dp[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};