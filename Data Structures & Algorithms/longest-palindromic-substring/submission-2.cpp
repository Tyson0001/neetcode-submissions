class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int idx=-1, maxlen=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<=n-1;j++){
                if(s[i]==s[j] && ((j-i)<2 || dp[i+1][j-1]==1)){
                    dp[i][j]=1;
                    if(maxlen <(j-i+1)){
                        maxlen=j-i+1;
                        idx=i;
                    }
                }
            }
        }
        return s.substr(idx,maxlen);
    }
};
