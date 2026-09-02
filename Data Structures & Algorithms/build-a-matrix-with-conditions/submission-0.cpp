class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rowindegree(k+1,0);
        vector<int>colindegree(k+1,0);
        vector<vector<int>>adjrow(k+1);
        vector<vector<int>>adjcol(k+1);
        queue<int>q;
        for(auto e:rowConditions){
            adjrow[e[0]].push_back(e[1]);
            rowindegree[e[1]]++;
        }
        for(int i=1;i<=k;i++){
            if(rowindegree[i]==0) q.push(i);
        }
        for(auto e:colConditions){
            adjcol[e[0]].push_back(e[1]);
            colindegree[e[1]]++;
        }
        unordered_map<int,int>row;
        int cnt=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            row[node]=cnt++;
            for(auto it:adjrow[node]){
                rowindegree[it]--;
                if(rowindegree[it]==0) q.push(it);
            }
        }
        
        if(row.size()<k) return {};
        unordered_map<int,int>col;
        for(int i=1;i<=k;i++){
            if(colindegree[i]==0) q.push(i);
        }
        cnt=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            col[node]=cnt++;
            for(auto it:adjcol[node]){
                colindegree[it]--;
                if(colindegree[it]==0) q.push(it);
            }
        }
        if(col.size()<k) return {};
        vector<vector<int>>mat(k,vector<int>(k,0));
        for(auto [num,i]:row){
            mat[i][col[num]]=num;
        }
        return mat;
    }
};