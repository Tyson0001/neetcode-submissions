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
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    void joint (int  u,int v){
        int pu=find(u) ,pv=find(v);
        if(pu==pv) return ;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else parent[pv]=pu, rank[pu]++;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DS ds(n);
        
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int  x1 =points[i][0] ,y1=points[i][1];
                int x2=points[j][0],y2=points[j][1];
                int wt =abs(x1-x2)+abs(y1-y2);
                edges.push_back({wt,i,j});
            }
        }
        int sum=0;
        sort(edges.begin(),edges.end());
        for(auto e:edges){
            int u=e[1],v=e[2],wt=e[0];
            if(ds.find(u)!=ds.find(v)){
                ds.joint(u,v);
                sum+=wt;
            }
        }
        return sum;
    }
};
