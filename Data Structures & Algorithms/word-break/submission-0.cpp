class Solution {
public: 
    int n;
    bool wordBreak(string s, vector<string>& wordDict) { 
        n=s.size(); 
        vector<int>dp(n,-1);
        unordered_set<string>st(wordDict.begin() ,wordDict.end());
        return solve(s,0,st,dp);
        
    }
    bool solve(string s , int idx ,unordered_set<string>&st,vector<int>&dp){
        if(idx==n) return true;  
        if(dp[idx]!=-1) return dp[idx];
        string str="";
        for(int i=idx;i<n;i++){
            str+=s[i];
            if(st.count(str)){
                if(solve(s,i+1,st,dp)) return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
};
