class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(); 
        string rev=s;
        reverse(rev.begin() ,rev.end()); 
        int cnt=0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i <=2 || dp[i+1][j-1]) ){
                    dp[i][j]=1;
                    
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};