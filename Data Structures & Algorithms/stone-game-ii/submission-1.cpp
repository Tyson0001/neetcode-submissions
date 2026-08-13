class Solution {
public:
    vector<int>prefix; 
    int n;
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        prefix.resize(n,0);
        prefix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--) prefix[i]=prefix[i+1]+piles[i]; 
        vector<vector<int>>dp(n,vector<int>(2*n,-1));
        return solve(piles,0,1,dp);
    }
    int solve(vector<int>&piles,int idx,int M , vector<vector<int>>&dp){
        if(idx>=n) return 0;
        int ans=0; 
        if(dp[idx][M]!=-1) return dp[idx][M];
        for(int i=idx;i<min(idx+2*M,n) ;i++){
            
            ans=max(ans, prefix[idx]-solve(piles,i+1,max(M,i-idx+1) , dp));
        }
        return dp[idx][M]=ans;
    }
};