class DS{
public:
    vector<int>parent;
    vector<int>rank;
    DS(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    void joint(int u ,int v){
        int pu=find(u) , pv=find(v);
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else parent[pv]=pu, rank[pu]++;
    }

};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        DS ds(m+n);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ds.joint(i,j+m);
                }
            }
        }
        unordered_map<int,int>map;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    map[ds.find(i)]++;
                }
            }
        }
        for(auto[num,cnt]:map){
            if(cnt>1) ans+=cnt;

        }
        return ans;
    }
};