class Solution {
public:
    string longestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin() ,rev.end());
        int n=s.size(); 
        int idx=-1, maxlen=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if (s[j-1] == s[i-1] && (i - j < 2 || dp[j+1][i-1])) {
                    dp[j][i] = 1;
                    int current_len = i - j + 1;
                    if (current_len > maxlen) {
                        maxlen = current_len;
                        idx = j - 1; // Record the position to extract it later
                    }
                }
                else dp[i][j]=0;
            }
        }
        if(idx==-1) return "";
        return s.substr(idx,maxlen);
    }
};
