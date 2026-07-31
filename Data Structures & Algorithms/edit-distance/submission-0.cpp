class Solution {
public: 
    int n , m;
    int minDistance(string word1, string word2) {
        n=word1.size() , m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(word1,word2,0,0,dp);
        
    }
    int solve(string word1, string word2,int i ,int j,vector<vector<int>>&dp){
        if(j==m){
            return n-i;
        }
        if(i==n) return m-j;  
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(word1[i]==word2[j]){
            take=solve(word1,word2,i+1,j+1,dp);
        }else{
            take=1+min({solve(word1,word2,i+1,j,dp) , solve(word1,word2,i,j+1,dp) ,solve(word1,word2,i+1,j+1,dp)});
        }
        return dp[i][j]=take;
    }
};
