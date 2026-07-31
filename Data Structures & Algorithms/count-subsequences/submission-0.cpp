class Solution {
public: 
    int n,m;
    int numDistinct(string s, string t) { 
        n=s.size() ,m=t.size(); 
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,t,0,0,dp);
    }
    int solve(string s , string t ,int i ,int j,vector<vector<int>>&dp){
        if(j==m) return 1;
        if(i==n) return 0;  
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(s[i]==t[j]){
            take+=solve(s,t,i+1,j+1,dp);
            take+=solve(s,t,i+1,j,dp);
        }else{
            take+=solve(s,t,i+1,j,dp);
        }
        return dp[i][j]=take;
    }
};
