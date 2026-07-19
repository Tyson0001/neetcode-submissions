class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(); 
        string rev=s;
        reverse(rev.begin() ,rev.end()); 
        int cnt=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(s[i-1]==s[j-1] && (i-j <2 || dp[j+1][i-1]) ){
                    dp[j][i]=1;
                    
                    cnt++;
                }else dp[j][i]=0;
                
            }
        }
        return cnt;
    }
};