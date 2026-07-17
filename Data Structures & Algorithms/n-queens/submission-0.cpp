class Solution {
public: 
    int n;
    vector<vector<string>> solveNQueens(int n) { 
        this->n=n;
        vector<vector<string>>ans;
        vector<string>temp;
        for(int i=0;i<n;i++){
            string t="";
            for(int j=0;j<n;j++){
                t+='.';
                
            }
            temp.push_back(t);
        }
        dfs(ans,temp,0);
        return ans;
    }
    void dfs(vector<vector<string>>&ans , vector<string>&temp,int col){
        if(col==n){
            ans.push_back(temp);
            return ;
        }
        for(int row=0;row<n;row++){
            if(check(temp,row,col)){
                temp[row][col]='Q';
                dfs(ans,temp,col+1);
                temp[row][col]='.';
            }
        }

    }
    bool check(vector<string>temp ,int row ,int col){
        int drow=row; 
        int dcol=col;
        while(dcol>=0){
            if(temp[row][dcol--]=='Q') return false;
        } 
        dcol=col;
        while(drow >=0 && dcol >=0){
            if(temp[drow--][dcol--]=='Q') return false;
        }
        while(row<n && col>=0){
            if(temp[row++][col--]=='Q') return false;
        }
        return true;
    }
};
