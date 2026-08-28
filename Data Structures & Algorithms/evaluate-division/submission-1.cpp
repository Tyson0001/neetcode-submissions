class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int>map; 
        int cnt=0;
        for(auto e:equations){
            if(map.find(e[0]) == map.end()){
                map[e[0]]=cnt;
                cnt++;
            }
            if(map.find(e[1]) == map.end()){
                map[e[1]]=cnt;
                cnt++;
            }

        }
        vector<vector<double>>dist(cnt,vector<double>(cnt,-1.0));
        for(int i=0;i<cnt;i++)dist[i][i]=1.0;
        for(int i=0;i<equations.size() ;i++ ){
            int u=map[equations[i][0]],v=map[equations[i][1]];
            dist[u][v]=values[i];
            dist[v][u]= 1/values[i];
        }
        for(int va=0;va<cnt;va++){
            for(int i=0;i<cnt;i++){
                for(int j=0;j<cnt;j++){
                    if(dist[i][va]==-1.0 || dist[va][j]==-1.0) continue;
                    if(dist[i][j]==-1.0){
                        dist[i][j]=dist[i][va]*dist[va][j];
                    }
                }
            }
        }
        int m=queries.size();
        vector<double>ans(m,-1.0);
        for(int i=0;i<m;i++){
            if(map.find(queries[i][0]) == map.end() || map.find(queries[i][1])==map.end()) continue;
            int u=map[queries[i][0]] ,v=map[queries[i][1]];
            ans[i]=dist[u][v];
        }
        return ans;
        
    }
};