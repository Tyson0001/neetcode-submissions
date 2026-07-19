class Solution {
public: 
    int n;
    int numDecodings(string s) {
        unordered_map<char ,string>map; 
        n=s.size();
        vector<int>dp(n,-1);
        return solve(s,0,dp);
    }
    int solve(string s ,int idx,vector<int>&dp){
        if(idx>=n){
            return 1;

        }
        if(dp[idx]!=-1) return dp[idx];
        int first =s[idx]-'0'; 
        if(first==0) return 0;
        int second=0;
        int take=solve(s,idx+1,dp);
        if(idx+1 <n){
            second =s[idx+1]-'0';
            
            int num =first*10 +second;
            if(num >=1 && num <=26){
                take+=solve(s,idx+2,dp);
            }
        }
        return dp[idx]=take;
    }
};
