class Solution {
public: 
    int ans=0; 
    int n;
    int totalNQueens(int n) {
        vector<string>temp; 
        this->n=n;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+='.';
            }
            temp.push_back(s);
        }
        dfs(temp,0);
        return ans;
    }
    void dfs(vector<string>&temp , int col){
        if(col==n){
            ans+=1;
            return ;
        }
        for(int row=0;row<n;row++){
            if(check(temp,row,col)){
                temp[row][col]='Q';
                dfs(temp,col+1);
                temp[row][col]='.';
            }
        }
    }
    bool check(vector<string>&temp ,int row ,int col){
        int dcol=col;
        int drow=row;
        while(dcol>=0){
            if(temp[row][dcol--]=='Q') return false;
        } 
        dcol=col;
        while(dcol>=0 && drow>=0){
            if(temp[drow--][dcol--]=='Q') return false;
        }
        while(row<n && col>=0){
            if(temp[row++][col--]=='Q') return false;
        }
        return true;
    }
};