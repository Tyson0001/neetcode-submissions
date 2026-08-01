class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size() ,m=p.size(); 
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,n-1,m-1,dp);
    }
    bool solve(string s , string p ,int i ,int j,vector<vector<int>>&dp){ 
        
        if(i<0){
            while(j>=0){
                if(p[j]=='*')j-=2;
                else return false;
            }
            return true;

        }
        if(j<0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='.'){
            if(solve(s,p,i-1,j-1,dp)) return dp[i][j]=true;
        }
        if(p[j]=='*'){
            if(solve(s,p,i,j-2,dp)) return dp[i][j]= true;
            if(p[j-1]==s[i] || p[j-1]=='.'){
                if(solve(s,p,i-1,j,dp)) return dp[i][j]= true;
            }
        }
        return dp[i][j]= false;
    }
};
