class Solution {
public: 
    int n ,x,y;
    bool isInterleave(string s1, string s2, string s3) {
        n=s3.size() ,x=s1.size(),y=s2.size(); 
        if(x+y !=n) return false;
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(x+1,vector<vector<int>>(y+1,vector<int>(3,-1))));
        return solve(s3,s1,s2,0,0,0,-1,dp);
    }
    bool solve(string s3, string s1 , string s2 , int i ,int j ,int idx,int flag,vector<vector<vector<vector<int>>>>&dp){
        if(idx==n){
            if(i==x && j==y) return true;
            return false;
        } 
        if(dp[idx][i][j][flag+1]!=-1) return dp[idx][i][j][flag+1];
        string str="";
        for(int p=idx;p<n;p++){
            str+=s3[p];
            if((flag==-1 || flag==0) && check(str,s1,i)){
                if(solve(s3,s1,s2,i+(p-idx+1),j,p+1,1,dp)) return dp[idx][i][j][flag+1]=true;
            }
            if((flag==-1 || flag==1) && check(str,s2,j)){
                if(solve(s3,s1,s2,i,j+(p-idx+1),p+1,0,dp)) return dp[idx][i][j][flag+1]=true;
            }
        }
        return dp[idx][i][j][flag+1]=false;
    }
    bool check(string str , string s ,int i){
        int len=str.size(); 
        int m=s.size();
        for(int q=0;q<len;q++){ 
            
            if( i+q>=m || str[q]!=s[i+q]) return false;
        }
        return true;
    }
};
