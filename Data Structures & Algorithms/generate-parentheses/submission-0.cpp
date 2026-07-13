class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        dfs(ans,temp,0,0,n);
        return ans;
    }
    void dfs(vector<string>&ans, string temp , int open , int close,int n){
        if(open==n && close==n){
            ans.push_back(temp);
            return ;
        }
        if(open<n)dfs(ans,temp+'(',open+1,close,n);
        if(close<open){
            dfs(ans,temp+')',open,close+1,n);
        }

    }
};
